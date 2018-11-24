
#include "MsgConnectEx.h"

#include <iostream>


const uint8_t MsgConnectEx::MSGCONNECTEX_INVALID_ACCOUNT[] = { // 帐号名或口令错 (1)
	0xD5, 0xca, 0xba, 0xc5, 0xc3, 0xfb, 0xbb, 0xf2,
	0xbf, 0xda, 0xc1, 0xee, 0xb4, 0xed, 0x00, 0x00 };
const uint8_t MsgConnectEx::MSGCONNECTEX_SERVER_DOWN[] = { // 服务器未启动 (10)
	0xb7, 0xfe, 0xce, 0xf1, 0xc6, 0xf7, 0xce, 0xb4,
	0xc6, 0xf4, 0xb6, 0xaf };
const  uint8_t MsgConnectEx::MSGCONNECTEX_LOGIN_LATER[] = { // 请稍后重新登录 (11)
	0xc7, 0xeb, 0xc9, 0xd4, 0xba, 0xf3, 0xd6, 0xd8,
	0xd0, 0xc2, 0xb5, 0xc7, 0xc2, 0xbc, 0x00, 0x00 };
const uint8_t MsgConnectEx::MSGCONNECTEX_BANNED_ACCOUNT[] = { // 该帐号被封号 (12)
	0xb8, 0xc3, 0xd5, 0xca, 0xba, 0xc5, 0xb1, 0xbb,
	0xb7, 0xe2, 0xba, 0xc5, 0x00, 0x00, 0x00, 0x00 };




MsgConnectEx::MsgConnectEx(uint32_t clientId, uint32_t port, uint8_t *ipAdress) :
	Msg()
{
	data = new mInfo;
	data->header.packetSize = sizeof(mInfo);
	data->header.packetID = 1055;
	data->clientId = clientId;
	data->authCode = 2;
	data->port = port;
	memcpy(data->ipAdress, ipAdress, 16);
}

MsgConnectEx::MsgConnectEx(uint32_t errorCode) :
	Msg()
{
	errData = new mError;
	errData->code = errorCode;
	errData->size = 28;
	switch (errorCode) {
		case 1:
			memcpy(errData->message, MSGCONNECTEX_INVALID_ACCOUNT, 16);
			break;
		case 10:
			memcpy(errData->message, MSGCONNECTEX_SERVER_DOWN, 12);
			break;
		case 11:
			memcpy(errData->message, MSGCONNECTEX_LOGIN_LATER, 16);
			break;
		case 12:
			memcpy(errData->message, MSGCONNECTEX_BANNED_ACCOUNT, 16);
			break;
	}
}