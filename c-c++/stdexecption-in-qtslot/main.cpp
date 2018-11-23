#include <QCoreApplication>
#include "thrower.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Thrower m_thrower;
	m_thrower.start();

	return a.exec();
}
