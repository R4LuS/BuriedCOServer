#ifndef SERVERTEST_H
#define SERVERTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QTCPServer>
#include <QDebug>

#include "session.h"
#include "DatabaseLocal/Database/DatabaseLocal.h"

class BAuthServer : public QObject
{
		Q_OBJECT
public:
	BAuthServer(QObject *parent = 0);
	static DatabaseLocal *getDB() { return db; }

signals:

public slots:
	void newConnection();

private:
	QTcpServer *server;
	std::vector<session *> sessions;

	static DatabaseLocal *db;
};



#endif // SERVERTEST_H
