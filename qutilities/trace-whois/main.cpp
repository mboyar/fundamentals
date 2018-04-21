#include <QCoreApplication>
#include "whois.h"
#include "traceroute.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Whois m_whois;
    Traceroute m_traceroute;

    return a.exec();
}
