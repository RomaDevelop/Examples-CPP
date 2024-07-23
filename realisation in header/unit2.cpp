#include "unit2.h"

#include <QDebug>

#include "HeaderWithRealisation.h"

Unit2::Unit2()
{
	Functions f;
	qDebug() << Functions::foo() << "Unit2::Unit2()" << f.a;
}
