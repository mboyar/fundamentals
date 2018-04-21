#ifndef WHOIS_H
#define WHOIS_H

#include <QObject>
#include <QProcess>

class Whois : public QObject
{
    Q_OBJECT
public:
    explicit Whois(QObject *parent = nullptr);

signals:

public slots:
    void readOutline();

private:
    QProcess proc;

};

#endif // WHOIS_H
