#ifndef SERVERTEST_H
#define SERVERTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QTCPServer>
#include <QDebug>

#include "session.h"

#include "World/World.h"

class BGameServer : public QObject
{
		Q_OBJECT
public:
	BGameServer(QObject *parent = 0);
	static DatabaseLocal *getDB() { return db; }
	static World *getWorld() { return world; }
signals:

public slots:
	void newConnection();

private:
	QTcpServer *server;
	std::vector<session *> sessions;

	static DatabaseLocal *db;
	static World *world;
};

#endif // SERVERTEST_H

// 089,041  coords main npc in main map
