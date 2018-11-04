#include "session.h"
#include <iostream>


session::session(QTcpSocket *socket, QObject *parent) :
	QObject(parent)
{
	this->socket = socket;
	static const char SEED[] = "DR654dt34trg4UI6";
	static const size_t SEED_LEN = strlen(SEED);
	static const uint8_t IV[Blowfish::BLOCK_SIZE] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

	Blowfish *cr = new Blowfish();
	cr->generateKey((const uint8_t*)SEED, SEED_LEN);
	cr->setIVs(IV, IV);
	this->cipher = cr;

	status = KEY_EXCHANGE;
}


void session::handle_data() 
{
	
	QByteArray buf = socket->readAll();
	uint8_t *readed = new uint8_t[buf.length()];
	fprintf(stdout, "[RECV]Size:%d\n", buf.length());
	memcpy(readed, reinterpret_cast<unsigned char*>(buf.data()), buf.length());
	cipher->decrypt(readed, buf.length());
	if (status == KEY_EXCHANGE) {
		fprintf(stdout, "[KEYEXCHANGE]\n");
		handleExchangeResponse(readed, buf.length());
		status = NORMAL;
	}
	else {
		Msg::Header *incomePacketInfo = new Msg::Header;
		incomePacketInfo = (Msg::Header *)readed;
		fprintf(stdout, "[PACKETINFO]Size: %d PacketID: %d \n", incomePacketInfo->packetSize, incomePacketInfo->packetID);
		Msg *msg;
		switch (incomePacketInfo->packetID) {
		case 1001:
			handler_1001((MsgRegister::MsgInfo *)readed);
			break;
		case 1052:
			handler_1052((MsgConnect::MsgInfo *)readed);
			break;
		default:
			break;
		}
	}
}

void session::handle_disconnect() {
	qDebug() << "[C]Disconnect...";
}

session::~session()
{
}



void session::generateExchangeRequest() {

	static const std::string P = "E7A69EBDF105F2A6BBDEAD7E798F76A209AD73FB466431E2E7352ED262F8C558F10BEFEA977DE9E21DCEE9B04D245F300ECCBBA03E72630556D011023F9E857F";
	static const std::string G = "05";
	mExchange = new DiffieHellman(P.c_str(), G.c_str());
	std::string pubKey = mExchange->generateRequest();
	mEncryptIV = new uint8_t[Blowfish::BLOCK_SIZE];
	mDecryptIV = new uint8_t[Blowfish::BLOCK_SIZE];
	fprintf(stdout, "[KEYEXCHANGE]Memory reserved, pub key created...\n");
	for (int32_t i = 0; i < Blowfish::BLOCK_SIZE; ++i)
	{
		mEncryptIV[i] = (uint8_t)(rand() - rand());
		mDecryptIV[i] = (uint8_t)(rand() + rand());
	}
	fprintf(stdout, "[KEYEXCHANGE]Generated IV...\n");
	MsgLoginProofA *msg = new MsgLoginProofA(mEncryptIV, mDecryptIV, P, G, pubKey);
	fprintf(stdout, "[KEYEXCHANGE]Created msg...\n");
	send(msg);
}

std::vector<char> HexToBytes(const std::string& hex);

void session::handleExchangeResponse(uint8_t* aBuf, size_t aLen)
{

	MsgLoginChallengeS::MsgInfo *someData = (MsgLoginChallengeS::MsgInfo *)aBuf;
	// aLen - (7 4 4 JunkSize) 
	
	int bsize = (int)aLen - 15 - someData->JunkSize - 8;
	int binit = 19 + someData->JunkSize;
	char *publicKey = new char[bsize + 1];
	fprintf(stdout, "[KEYEXCHANGE-RES]Size:%d %d\n", bsize, binit);
	int i = 0;
	for (i = binit; i < (int)aLen - 8; i++) {
		publicKey[i - binit] = aBuf[i];
	}
	publicKey[i - binit] = '\0';
	std::string s_key = mExchange->handleResponse(reinterpret_cast<char *>(publicKey));

	fprintf(stdout, "[KEYESCHANGE-RES]Key s generated...\n");
	std::vector<char> seed = HexToBytes(s_key);
	cipher->generateKey((uint8_t *)seed.data(), seed.size());
	cipher->setIVs(mEncryptIV, mDecryptIV);
}


static const char SEAL[] = "TQServer";
static const size_t SEAL_LEN = strlen(SEAL);

void session::send(Msg *msg) 
{
	const size_t finalLen = msg->getSize() + SEAL_LEN;
	uint8_t *msgToSend = new uint8_t[finalLen];
	memcpy(msgToSend, msg->getInfo(), msg->getSize());
	memcpy(msgToSend + msg->getSize(), SEAL, SEAL_LEN);
	cipher->encrypt(msgToSend, finalLen);
	fprintf(stdout, "[SEND]%d %d\n", finalLen, msg->getSize());
	socket->write(QByteArray(reinterpret_cast<char *>(msgToSend), finalLen));
}

std::vector<char> HexToBytes(const std::string& hex) 
{
	std::vector<char> bytes;

	for (unsigned int i = 0; i < hex.length(); i += 2) {
		std::string byteString = hex.substr(i, 2);
		char byte = (char)strtol(byteString.c_str(), NULL, 16);
		bytes.push_back(byte);
	}

	return bytes;
}