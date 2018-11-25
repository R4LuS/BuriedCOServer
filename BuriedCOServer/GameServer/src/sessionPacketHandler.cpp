
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

void session::handler_1009(MsgItem::MsgInfo *stData) {
	switch (stData->action) {
		case MsgItem::ACTION_BUY:
			break;
		case MsgItem::ACTION_COMPLETE_TASK:
			send(new MsgItem(stData));
			break;
		default:
			break;
	}
}

void session::handler_1010(MsgAction::MsgInfo *stData) {
	switch (stData->action) {
		case MsgAction::ACTION_ENTER_MAP:
			stData->posX = 200;
			stData->posY = 200;
			stData->data = 1010;
			stData->direction = 1;
			send(new MsgAction(stData));
			break;
		default:
			break;
	}

}

void session::handler_1052(MsgConnect::MsgInfo *stData) 
{
	Msg *msg;

	account = BGameServer::getDB()->getByID(stData->clientID);
	if (account == nullptr) {
		fprintf(stdout, "[1052]Account %d doesnt exists...\n", stData->clientID);
		return;
	}

	if (account->getCharacter() != nullptr) {
		/* Create character msg */
		msg = new MsgTalk(STR_SYSTEM_NAME, STR_ALLUSERS_NAME, STR_REPLY_NEW_ROLE, MsgTalk::CHANNEL_ENTRANCE);
	}
	else {
		/* Send ok to join server */
		msg = new MsgTalk(STR_SYSTEM_NAME, STR_ALLUSERS_NAME, STR_REPLY_OK, MsgTalk::CHANNEL_ENTRANCE);
	}
	send(msg);

	// MsgDate()
	msg = new MsgDate();
	send(msg);

	/* Send player data */
	// MsgUserInfo()	
	msg = new MsgUserInfo();
	send(msg);

	/* Send some info creator/build */
	// MsgTalk()
	msg = new MsgTalk(STR_SYSTEM_NAME, STR_ALLUSERS_NAME, "BuriedCO-v4", MsgTalk::CHANNEL_TALK);
	send(msg);

	/* Send server info */
	// MsgTalk
	msg = new MsgTalk(STR_SYSTEM_NAME, STR_ALLUSERS_NAME, "Build for windows, with qt", MsgTalk::CHANNEL_TALK);
	send(msg);

	/* Load player items */

	/* Load player wep skills */

	/* Load player magic skills */

}

