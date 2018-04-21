#include "traceroute.h"

Traceroute::Traceroute(QObject *parent) : QObject(parent)
{
    proc.setProgram("traceroute");
    proc.setArguments(QStringList() << QCoreApplication::arguments().at(1));
    proc.start();
    proc.waitForFinished();
    qDebug() << proc.readAll();
}

void Traceroute::readOutline()
{

}
