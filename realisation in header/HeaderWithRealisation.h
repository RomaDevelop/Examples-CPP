#ifndef HEADERWITHREALISATION_H
#define HEADERWITHREALISATION_H

struct Functions
{
	int a;
	inline static int foo();
	inline Functions();
};

int Functions::foo()
{
	return 5;
}

Functions::Functions() { a=6; }

#endif // HEADERWITHREALISATION_H



