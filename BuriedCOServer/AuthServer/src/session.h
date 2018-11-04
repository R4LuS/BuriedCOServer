#ifndef _SESSION_H
#define _SESSION_H

#include <QObject>
#include <QTcpSocket>

#include "Security/tqcipher.h"
#include "Msg/Msg.h"
#include "Msg/MsgConnectEx.h"
#include "Msg/MsgAccount.h"
#include "Security/rc5.h"

#include "Database/DatabaseLocal.h"

class session : public QObject
{
	Q_OBJECT
public:
	explicit session(QTcpSocket *socket, QObject *parent = 0);
	~session();

	ICipher *get_cipher() { return this->cipher; }
	void send(MsgConnectEx *msg);

signals:

public slots:
	void handle_data();
	void handle_disconnect();

	//packet handler
private:
	void handler_1051(MsgAccount::MsgInfo *);

private:
	QTcpSocket *socket;
	ICipher *cipher;

	
};

#endif