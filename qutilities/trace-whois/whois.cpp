#include "whois.h"
#include <QCoreApplication>
#include <QDebug>

Whois::Whois(QObject *parent) : QObject(parent)
{
    proc.setProgram("whois");
    proc.setArguments(QStringList() << QCoreApplication::arguments().at(1));
    proc.start();
    proc.waitForFinished();
    qDebug() << proc.readAll();
}

void Whois::readOutline()
{

}
