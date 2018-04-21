#ifndef TRACEROUTE_H
#define TRACEROUTE_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QCoreApplication>

class Traceroute : public QObject
{
    Q_OBJECT
public:
    explicit Traceroute(QObject *parent = nullptr);

signals:

public slots:
    void readOutline();

private:
    QProcess proc;
};

#endif // TRACEROUTE_H
