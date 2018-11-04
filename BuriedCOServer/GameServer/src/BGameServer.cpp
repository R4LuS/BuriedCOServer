#include "BGameServer.h"

DatabaseLocal *BGameServer::db = new DatabaseLocal();

BGameServer::BGameServer(QObject *parent) :
	QObject(parent)
{
	server = new QTcpServer(this);

	connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

	if (!server->listen(QHostAddress::Any, 5516)) {
		qDebug() << "Server could not start";
	}
	else {
		qDebug() << "Server started!";
	}

	db->loadAccounts("accounts.data");
}


void BGameServer::newConnection() {
	QTcpSocket *socket = server->nextPendingConnection();
	session *newsession = new session(socket);

	connect(socket, SIGNAL(readyRead()), newsession, SLOT(handle_data()));
	connect(socket, SIGNAL(disconnected()), newsession, SLOT(handle_disconnect()));

	sessions.push_back(newsession);

	newsession->generateExchangeRequest();
}
