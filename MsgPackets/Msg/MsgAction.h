#pragma once

#include "Msg.h"

class MsgAction : public Msg
{
public:
	enum Action
	{
		/** No action specified. (Invalid) */
		ACTION_NONE = 0,
		/** Change the direction of an entity */
		ACTION_CHG_DIR = 79,
		/** Change the emotion of an entity */
		ACTION_EMOTION = 81,
		/** Signal to the server that the client entered in a portal. */
		ACTION_CHG_MAP = 85,
		/** Signal to the client that the player is changing map. */
		ACTION_FLY_MAP = 86,
		/** Set the position of an entity entering in a new map */
		ACTION_ENTER_MAP = 74,
		/** Get the items (client request). The next step is the friends. */
		ACTION_GET_ITEM_SET = 75,
		/** Get the friends (client request). The next step is the weapon skills. */
		ACTION_GET_GOOD_FRIEND = 76,
		/** Signal to the client that the entity leaved the map. */
		ACTION_LEAVE_MAP = 132,
		/** Signal to both sides that an entity jumped. */
		ACTION_JUMP = 133,
		/** Signal to the client that the player gained a level */
		ACTION_UP_LEVEL = 92,
		/** Signal to the client that the XP is done. */
		ACTION_XP_CLEAR = 93,
		/** Signal to both sides that the entity will reborn. */
		ACTION_REBORN = 94,
		/** Delete the current role. */
		ACTION_DELETE_ROLE = 95,
		/** Get the weapon skills (client request). The next step is the magics. */
		ACTION_GET_WEAPON_SKILL_SET = 77,
		/** Get the magics (client request). The next step is the legion attributes. */
		ACTION_GET_MAGIC_SET = 78,
		/** Set the Pk mode of an entity */
		ACTION_SET_PKMODE = 96,
		/** Get the legion attributes. */
		ACTION_GET_SYN_ATTR = 97,
		/** Signal to the client to transform in a ghost. */
		ACTION_GHOST = 137,
		/** Synchronize the position (the client will send its coords) as answer */
		ACTION_SYNCRHO = 138, // Unknown action[0032], data=[54788624]
		/** Change the face of the entity */
		ACTION_CHANGE_FACE = 142,
		/** Signal to both sides that the entity is mining. */
		ACTION_MINE = 99,
		/** Request a player to the server. */
		ACTION_QUERY_PLAYER = 102,
		/** Set the color of the map */
		ACTION_MAP_ARGB = 104,
		/** Signal to client/server a new booth. */
		ACTION_CREATE_BOOTH = 111, // UID: playerID; PosX,Y: playerpos; unDir:dirofbooth; idTarget:idnpc;
		/** Destroy the booth */
		ACTION_DESTROY_BOOTH = 114,
		/** Post a command to the client. */
		ACTION_POST_CMD = 116, // to client only
		/** Abort the current transformation. */
		ACTION_ABORT_TRANSFORM = 118, // to server
		/** Signal to the client that the player picked up some money. */
		ACTION_GET_MONEY = 121, // to client only // ºÒµΩ500“‘º∞500“‘…œ«Æ£¨÷ª¥´∏¯◊‘º∫£¨dwDataŒ™ºÒµΩµƒ«Æ
		/** Kick back the player at a previous position (the client answer with ACTION_SYNCHRO) */
		ACTION_KICK_BACK = 108, // to client    idUser is Player ID, unPosX unPosY is Player pos
		/** Open a dialog on the client. */
		ACTION_OPEN_DIALOG = 126 // to client only, open a dialog, dwData is id of dialog
	};

public:
	typedef struct {
		Msg::Header header;
		int32_t timestamp;
		uint32_t uniqId;
		int32_t data;
		uint16_t posX;
		uint16_t posY;
		uint16_t direction;
		uint16_t action;
	}MsgInfo;

public:
	MsgAction();
	MsgAction(MsgInfo *);

	uint8_t *getInfo() { return (uint8_t *)data; }
	uint16_t getSize() { return size; }

private:
	MsgInfo *data;
	uint16_t size;
};