struct A
{
public:
	virtual void F() = 0;
private:
	virtual void F2() = 0;
};

struct B: public A
{
private:
	virtual void F() { qdbg << "B->F"; }
public:
	virtual void F2() { qdbg << "B->F2"; }
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget window;
	window.show();

	B *b = new B;
	A *a = b;

	a->F();
	//b->F(); // не компилируется

	//a->F2(); // не компилируется
	b->F2();

	return app.exec();
}
