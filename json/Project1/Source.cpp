#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "nlohmann\\json.hpp"

using json = nlohmann::json;
using namespace std;

// ����� ��������� ������ � ����� ����� ��� ������������
void printTypes(json JcellTyps) {
	for (auto &c : JcellTyps.items()) {
		cout << c.key() << endl;
		cout << "width: " << JcellTyps[c.key()]["width"] << endl;
		cout << "pins: " << endl;
		for (auto &p : JcellTyps[c.key()]["pins"].items())
			cout << p.key() << " : " << p.value() << endl;
		//cout << p;
	}
}

// ����� ��������� ������ � ������� ��� ������������
void printCells(json Jcells) {  
	for (auto &c : Jcells["cells"].items()) {
		cout << c.key() << endl;
		cout << "type: " << c.value()["type"] << endl;
		cout << "connections: " << endl;
		for (auto &conn : c.value()["connections"].items()) {
			cout << conn.key() << ":" << conn.value() << endl;
		}
	}
}

// class Cell ��� �������� ���������� �����, � ����� ���, � ��� � ������.
// count_contacts � connects ����������� ������������ � ���������� ���������� � ��������� ����������� ���������
class Cell {
public:
	string name;
	string type;
	int w;
	static const int h = 1;
	int x;
	int y;
	int count_contacts;
	vector <string> connects;

	Cell(string name_, string type_, int w_) : name{ name_ }, type{ type_ }, w{ w_ } {}
};

// class Field ������ ������� ���� � � ��� ���������� ������� ���������� �����
class Field {
public:
	int x;
	int y;
	Field() : x{ 0 }, y{ 0 } {}
	Field(int x_, int y_) : x{ x_ }, y{ y_ } {}

	// PlacementAsCol ��������� ������ � �������.
	void PlacementAsCol(vector <Cell> &Cells) {
		
		int fieldH = 0;
		int fieldW = 0;
		int free_x = 0;
		int free_y = 0;

		for (auto &c : Cells) {
			c.x = free_x;
			c.y = free_y;

			//free_y += c.h + 1;    // � ������������
			free_y += c.h;			// ��������

			if (fieldW < c.w) fieldW = c.w;
		}
		fieldH = free_y;

		x = fieldW;
		y = fieldH;
	}
}; 


json JcellTyps;
json Jcells;

int GetW(string Type) { return JcellTyps[Type]["width"]; }  // �� ���� ������ ���������� � ������

int main() {

	string cells, types, output;
	cells = "tests\\test1\\input.json";
	types = "tests\\test1\\cells.json";
	output = "tests\\test1\\results\\output2.json";
	//cin >> cells >> types >> output;

	ifstream f1(types);
	ifstream f2(cells);
	JcellTyps = json::parse(f1);
	Jcells = json::parse(f2);

	// �������� ����� �����
	//cout << "\n\nCheck cell types" << endl;
	//printTypes(JcellTyps);
	//cout << endl;

	// �������� ����� �����
	//cout << "\n\nCheck cells" << endl;
	//printCells(Jcells);
	//cout << endl;

	vector <Cell> Cells; // ��������� ����� ��� ����� ��������� ���������� �����

	for (auto &c : Jcells["cells"].items()) {
		Cells.push_back(Cell(c.key(), c.value()["type"], GetW(c.value()["type"])));  // ���������� ������ � ��������� (���, � ���, ������)
	}
	//for (auto c : Cells) cout << c.name << " " << c.type << " " << c.w << endl;   // �������� �����

	Field f;
	f.PlacementAsCol(Cells);  // ���������� ����� �� ���������
	/*
	PlacementAsCol ��������� ������ � �������. 
	� ����� � ���������� ��������� ����������: � ����� ��������� ������ � ���������� ������ ����������, 
	�� ��������� ��������� ����������� � ��� ������, ����� � ���� ����������� � ���� � ��. 
	�� ������������ ������ ��������� ������� � ���� ��������� � ������ �� ������� ������ �������.
	*/

	/*
	��� ������ ���� ��������� ����������� ���������, �� �� ����� �������.
	� ���������� ��������� ��� ��������, ��� ����� ��������� �� ���� ���������������, ������ "�" 
	��� �� ��� ���������������, ������ N.
	����� ��������� ��, ��� �� ����������� ������� � � N �� ���� wires1.
	� ����� ��������� � ���������� �� ���� �� ����.
	���, �������, ��� �������, ��� ���������� �������� ����������.
	*/

	// ������������ � ������ ��������� �����
	json Joutput;
	for (auto &c : Cells) {
		Joutput["cells"][c.name] = { c.type, c.x, c.y };
	}
	Joutput["size"] = { f.x , f.y };

	ofstream out(output);
	out << std::setw(4) << Joutput;

	system("pause");
	return 0;
}