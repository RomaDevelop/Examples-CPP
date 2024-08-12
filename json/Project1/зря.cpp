class Pin {
public:
	string name;
	float x1;
	float y1;
	float x2;
	float y2;

	Pin(string name_, float koord[4]) {
		name = name_;
		x1 = koord[0];
		y1 = koord[1];
		x2 = koord[2];
		y2 = koord[3];
	}
};

class CellType{
   public:
	string nameType;
	static const int h = 1;
	int width;
	vector <Pin> pins;

	CellType() {}
	CellType(string nameType_) : nameType{ nameType_ } {}

	bool operator== (string name) { return (nameType == name); }

	void print() {
		cout << nameType << "\n\twidth: " << width << endl;
		cout << "\tpins: " << endl;
		for (auto &p : pins)
			cout << "\t\t" << p.name << " : " << p.x1 << " " << p.y1 << " " << p.x2 << " " << p.y2 << endl;
	}
	
	static void Load(json &data, vector <CellType> &cellTs) {
		for (auto &d : data.items()) {
			//cout << d.key() << ":" << d.value() << endl;
			cellTs.push_back(d.key());
		}

		for (auto &c : cellTs) {
			c.width = data[c.nameType]["width"];
			int s = data[c.nameType]["width"];
			for (auto &p : data[c.nameType]["pins"].items()) {
				//cout << p.key() <<" "<< p.value()[0] << endl;
				float pf[4] = { p.value()[0], p.value()[1], p.value()[2], p.value()[3] };
				c.pins.push_back(Pin(p.key(), pf));
			}
		}
	}
};
CellType findCellType(vector <CellType> cellTs, string nameType_) {
	for (auto &t : cellTs)
		if (t.nameType == nameType_) return t;
	cout << "Error findCellType!!!";
	return CellType();
}

class Connection
{
	Pin pin;
	string nameConnection;
};

class Cell
{
   public:
	string nameCell;
	CellType type;
	vector <Connection> connections;
	int x;
	int y;

	Cell() : x{ -1 }, y{ -1 } {}
	Cell(string name, CellType type_) {
		nameCell = name;
		type = type_;
		x = -1;
		y = -1;
	}
};