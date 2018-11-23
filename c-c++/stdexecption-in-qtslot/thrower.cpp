#include "thrower.h"

Thrower::Thrower(QObject *parent) : QObject(parent)
{
	tmr = new QTimer(this);

	QStringList args = QCoreApplication::arguments();

	if(args.count() == 2)
	{
		if(args.at(1).compare("unhandled") == 0)
		{
			connect(tmr, SIGNAL(timeout()), this, SLOT(throwUnhandledException()));
		}
	}
	else
	{
		connect(tmr, SIGNAL(timeout()), this, SLOT(throwHandledException()));
	}
}

void Thrower::start()
{
	throwNo = 0;
	tmr->start(1000);
}

void Thrower::thrower()
{
	throw ++throwNo;
}

void Thrower::throwHandledException()
{
	try {
		thrower();
	} catch (int x) {
		qDebug() << "Handled error no:" << x;
	}

	/* stdout:
	 * Handled error no: 1
	Handled error no: 2
	Handled error no: 3
	Handled error no: 4
	Handled error no: 5
	Handled error no: 6
	Handled error no: 7
	Handled error no: 8
	 */
}

void Thrower::throwUnhandledException()
{
	thrower();

	/* stdout:
	 * Qt has caught an exception thrown from an event handler. Throwing
	exceptions from an event handler is not supported in Qt. You must
	reimplement QApplication::notify() and catch all exceptions there.

	terminate called after throwing an instance of 'int'
	Aborted (core dumped)
	*/
}
