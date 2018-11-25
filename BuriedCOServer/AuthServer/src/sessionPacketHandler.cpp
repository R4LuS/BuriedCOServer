
#include "session.h"
#include "BAuthServer.h"


void session::handler_1051(MsgAccount::MsgInfo *stData) {
	uint8_t seed[RC5::KEY_SIZE] =
	{ 0x3C, 0xDC, 0xFE, 0xE8, 0xC4, 0x54, 0xD6, 0x7E, 0x16, 0xA6, 0xF8, 0x1A, 0xE8, 0xD0, 0x38, 0xBE };
	
	RC5 cipher;
	cipher.generateKey(seed);
	cipher.decrypt((uint8_t *)stData->password, sizeof(stData->password));

	DatabaseLocal *db = BAuthServer::getDB();
	if (db->validAccount(QByteArray(reinterpret_cast<char *>(stData->name), (int)strlen((char *)stData->name)),	
		QByteArray(reinterpret_cast<char *>(stData->password), (int)strlen((char *)stData->password)))) {
		AccountLocal *acc = db->getByName(QByteArray(reinterpret_cast<char *>(stData->name), (int)strlen((char *)stData->name)));

		/*************************************************************************************************/
		/*************************************************************************************************/
		/*************************************************************************************************/
		send(new MsgConnectEx((uint32_t)acc->getUniqueID(), (uint32_t)5516, (uint8_t *)"192.168.1.43"));
	}
}