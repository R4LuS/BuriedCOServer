#include <QCoreApplication>
#include <QtNetwork>

#include "BGameServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	system("title [BuriedCO]GameServer");
	BGameServer ts;
    return a.exec();
}
