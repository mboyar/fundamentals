#ifndef THROWER_H
#define THROWER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QCoreApplication>
#include <QStringList>

class Thrower : public QObject
{
	Q_OBJECT
public:
	explicit Thrower(QObject *parent = nullptr);
	void start();

signals:

public slots:

private:
	void thrower();
	QTimer *tmr;
	int throwNo;

private slots:
	void throwHandledException();
	void throwUnhandledException();

};

#endif // THROWER_H

//according to http://doc.qt.io/qt-5/exceptionsafety.html
