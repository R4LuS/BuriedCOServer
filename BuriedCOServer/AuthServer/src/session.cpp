#include "session.h"

#include <iostream>


session::session(QTcpSocket *socket, QObject *parent) :
	QObject(parent)
{
	this->socket = socket;
	TqCipher *cr = new TqCipher();
	cr->generateIV(0x13FA0F9D, 0x6D5C7962);
	this->cipher = cr;

	

}


void session::handle_data() 
{
	QByteArray buf = socket->readAll();
	uint8_t *readed = new uint8_t[buf.length()];
	memcpy(readed, reinterpret_cast<unsigned char*>(buf.data()), buf.length());
	
	cipher->decrypt(readed, buf.length());

	Msg::Header *incomePacketInfo = new Msg::Header;
	incomePacketInfo = (Msg::Header *)readed;
	fprintf(stdout, "Size: %d PacketID: %d \n", incomePacketInfo->packetSize, incomePacketInfo->packetID);

	switch(incomePacketInfo->packetID){
		case 1051:
			handler_1051((MsgAccount::MsgInfo *)readed);
			break;
		default:
			break;
	}
	
}

void session::handle_disconnect() {
	qDebug() << "[C]Disconnect...";
}

session::~session()
{
}



static const char SEAL[] = "TQServer";
static const size_t SEAL_LEN = strlen(SEAL);



void session::send(MsgConnectEx *msg) 
{
	const size_t finalLen = msg->getSize() + SEAL_LEN;
	uint8_t *msgToSend = new uint8_t[finalLen];
	memcpy(msgToSend, msg->getInfo(), msg->getSize());
	memcpy(msgToSend + msg->getSize(), SEAL, SEAL_LEN);
	cipher->encrypt(msgToSend, finalLen);
	socket->write(QByteArray(reinterpret_cast<char *>(msgToSend), finalLen));
	SAFEDELETE(msgToSend);

}