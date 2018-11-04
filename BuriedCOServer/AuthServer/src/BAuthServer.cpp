#include "BAuthServer.h"

DatabaseLocal *BAuthServer::db = new DatabaseLocal();

BAuthServer::BAuthServer(QObject *parent) :
	QObject(parent)
{
	server = new QTcpServer(this);

	connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

	if (!server->listen(QHostAddress::Any, 9958)) {
		qDebug() << "Server could not start";
	}
	else {
		qDebug() << "Server started!";
	}

	db->loadAccounts("accounts.data");
}


void BAuthServer::newConnection() {
	QTcpSocket *socket = server->nextPendingConnection();
	session *newsession = new session(socket);
	qDebug() << "New client....";
	connect(socket, SIGNAL(disconnected()), newsession, SLOT(handle_disconnect()));
	connect(socket, SIGNAL(readyRead()), newsession, SLOT(handle_data()));
	sessions.push_back(newsession);

}
