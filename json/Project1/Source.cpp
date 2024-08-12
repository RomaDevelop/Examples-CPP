#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "nlohmann\\json.hpp"

using json = nlohmann::json;
using namespace std;

// вывод считанных данных о типах €чеек дл€ тестировани€
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

// вывод считанных данных о €чейках дл€ тестировани€
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

// class Cell где хран€тс€ координаты €чеек, а также им€, еЄ тип и ширина.
// count_contacts и connects предполагал использовать в алгоритмах размещени€ и установки соединейний контактов
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

// class Field хранит размеры пол€ и в нем определена функци€ размещени€ €чеек
class Field {
public:
	int x;
	int y;
	Field() : x{ 0 }, y{ 0 } {}
	Field(int x_, int y_) : x{ x_ }, y{ y_ } {}

	// PlacementAsCol размещает €чейки в столбик.
	void PlacementAsCol(vector <Cell> &Cells) {
		
		int fieldH = 0;
		int fieldW = 0;
		int free_x = 0;
		int free_y = 0;

		for (auto &c : Cells) {
			c.x = free_x;
			c.y = free_y;

			//free_y += c.h + 1;    // с промежутками
			free_y += c.h;			// вплотную

			if (fieldW < c.w) fieldW = c.w;
		}
		fieldH = free_y;

		x = fieldW;
		y = fieldH;
	}
}; 


json JcellTyps;
json Jcells;

int GetW(string Type) { return JcellTyps[Type]["width"]; }  // по типу €чейки возвращает еЄ ширину

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

	// тестовый вывод типов
	//cout << "\n\nCheck cell types" << endl;
	//printTypes(JcellTyps);
	//cout << endl;

	// тестовый вывод €чеек
	//cout << "\n\nCheck cells" << endl;
	//printCells(Jcells);
	//cout << endl;

	vector <Cell> Cells; // коллекци€ €чеек где будут хранитьс€ координаты €чеек

	for (auto &c : Jcells["cells"].items()) {
		Cells.push_back(Cell(c.key(), c.value()["type"], GetW(c.value()["type"])));  // добавление €чейки в коллекцию (им€, еЄ тип, ширина)
	}
	//for (auto c : Cells) cout << c.name << " " << c.type << " " << c.w << endl;   // тестовый вывод

	Field f;
	f.PlacementAsCol(Cells);  // размещение €чеек по алгоритму
	/*
	PlacementAsCol размещает €чейки в столбик. 
	я думал о улучшенном алгоритме размещени€: в центр размещать €чейку с наибольшим числом соединений, 
	по соседству размещать соединенные с ней €чейки, р€дом с ними соединенные с ними и тд. 
	Ќо формирование такого алгоритма вызвало у мен€ сложности и зан€ло бы гораздо больше времени.
	*/

	/*
	“ут должна быть установка соединейний контактов, но не успел сделать.
	я планировал соединить все контакты, что можно контактом из двух пр€моугольников, буквой "√" 
	или из трЄх пр€моугольников, буквой N.
	«атем соединить то, что не соединилось буквами √ и N на слое wires1.
	» затем соедин€ть с переходами из сло€ на слой.
	Ёто, конечно, сще сложнее, чем нормальный алгоритм размещени€.
	*/

	// формирование и запись выходного файла
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