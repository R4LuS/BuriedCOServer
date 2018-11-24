
#include "session.h"
#include "BGameServer.h"

// Macro to convert from uint8_t* to QByteArray
#define C2QBA(x) (QByteArray(reinterpret_cast<char *>(x), (int)strlen((char *)x)))

void session::handler_1001(MsgRegister::MsgInfo *stData) 
{
	Msg *msg;

	DatabaseLocal *db = BGameServer::getDB();


	if (db->validAccount(C2QBA(stData->username), C2QBA(stData->password))) {
		//account->createCharacter()
	}

	// If everything is ok(created character...)
	msg = new MsgTalk(STR_SYSTEM_NAME, STR_ALLUSERS_NAME, STR_REPLY_OK, MsgTalk::CHANNEL_REGISTER);
	
	send(msg);
}

void session::handler_1052(MsgConnect::MsgInfo *stData) 
{
	Msg *msg;

	account = BGameServer::getDB()->getByID(stData->clientID);
	if (account == nullptr) {
		fprintf(stdout, "[1052]Account %d doesnt exists...\n", stData->clientID);
		return;
	}

	if (account->getCharacter() == nullptr) {
		/* Create character msg */
		msg = new MsgTalk(STR_SYSTEM_NAME, STR_ALLUSERS_NAME, STR_REPLY_NEW_ROLE, MsgTalk::CHANNEL_ENTRANCE);
	}
	else {
		/* Send ok to join server */
		msg = new MsgTalk(STR_SYSTEM_NAME, STR_ALLUSERS_NAME, STR_REPLY_OK, MsgTalk::CHANNEL_ENTRANCE);
	}
	send(msg);


	/* Send player data */

	/* Send some info creator/build */

	/* Send server info */

	/* Load player items */

	/* Load player wep skills */

	/* Load player magic skills */

}