#include <QCoreApplication>
#include <QtNetwork>
#include "openssl/dh.h"

#include "BAuthServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	system("title [BuriedCO]AuthServer");
	BAuthServer ts;
    return a.exec();
}
