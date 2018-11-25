#pragma once

#include "Msg.h"
#include "./Common/endianness.h"

class MsgConnectEx : public Msg
{
public:
	static const uint8_t MSGCONNECTEX_INVALID_ACCOUNT[]; 
	static const uint8_t MSGCONNECTEX_SERVER_DOWN[];
	static const uint8_t MSGCONNECTEX_LOGIN_LATER[];
	static const uint8_t MSGCONNECTEX_BANNED_ACCOUNT[];

#pragma pack(push, 1)
	typedef struct {
		Msg::Header header;
		uint32_t clientId;
		uint32_t authCode;
		uint8_t ipAdress[16];
		uint32_t port;
	}mInfo;
#pragma pack(pop)

	typedef struct {
		uint16_t size;
		uint16_t packetId;
		uint32_t code;
		uint8_t message[16];
	}mError;

public:
	MsgConnectEx(uint32_t clientId, uint32_t port, uint8_t *ipAdress);
	MsgConnectEx(uint32_t errorCode);
	uint8_t *getInfo() { return (uint8_t *)data; }
	uint16_t getSize() { return size; }
	uint8_t *getError() { return (uint8_t *)errData; }

private:
	mInfo *data;
	uint16_t size;
	mError *errData;
	
};