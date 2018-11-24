#pragma once

#include <QObject>
#include <QTcpSocket>

#include "Security/tqcipher.h"
#include "Security/diffiehellman.h"
#include "Security/blowfish.h"
#include "Security/rc5.h"
#include "Msg/AllMsg.h"

#include "Database/AccountLocal.h"

class session : public QObject
{
	Q_OBJECT
public:
	explicit session(QTcpSocket *socket, QObject *parent = 0);
	~session();

	ICipher *get_cipher() { return this->cipher; }
	void generateExchangeRequest();
	void handleExchangeResponse(uint8_t* aBuf, size_t aLen);
	void send(Msg *msg);

	AccountLocal *getAccount() { return account; }

	enum Status {
		KEY_EXCHANGE,
		NORMAL
	};

signals:

public slots:
	void handle_data();
	void handle_disconnect();


private: //packet handler
	/* MsgRegister */
	void handler_1001(MsgRegister::MsgInfo *);
	/* MsgConnect */
	void handler_1052(MsgConnect::MsgInfo *);



private:
	QTcpSocket *socket;
	Blowfish *cipher;
	
	DiffieHellman* mExchange; //!< the key exchange of the client
	uint8_t* mEncryptIV; //!< the new encryption IV (in the exchange)
	uint8_t* mDecryptIV;  //!< the new decryption IV (in the exchange)

	Status status;

	AccountLocal *account;
};
