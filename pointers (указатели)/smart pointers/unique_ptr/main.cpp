
#include <iostream>
using namespace std;

#include "unique_ptr.h"

#include <QDebug>

class Object{
public:
	Object() { qDebug() << "Object()\n"; };
	Object(Object &obj) { obj.void_foo(); qDebug() << "Object(Object &obj)\n"; };
	Object(Object &&obj) { obj.void_foo(); qDebug() << "Object(Object &&obj)\n"; };
	~Object() { qDebug() << "~Object()\n"; };

	void void_foo() {}
};

int main()
{
	unique_ptr<Object> uptr = make_unique<Object>();
	//unique_ptr<Object> uptr2 = std::move(uptr);
	uptr = make_unique<Object>();

	return 0;
}
