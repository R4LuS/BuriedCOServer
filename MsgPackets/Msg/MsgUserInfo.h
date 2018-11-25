#pragma once

#include "Msg.h"
#include "BuriedCOServer/GameServer/src/Player.h"

class MsgUserInfo : public Msg 
{
public:

#pragma pack(push, 1)
	typedef struct 
	{
		Msg::Header header;
		uint32_t id;
		uint32_t mesh;
		uint16_t hairstyle;
		uint32_t silver;
		uint32_t cps;
		uint64_t experience;
		uint8_t padding[20];
		uint16_t strength;
		uint16_t agility;
		uint16_t vitality;
		uint16_t spirit;
		uint16_t extraPoints;
		uint16_t health;
		uint16_t mana;
		uint16_t pkpoints;
		uint8_t level;
		uint8_t cclass; //current
		uint8_t pclass; //previus
		uint8_t rebirth;
		uint8_t showname;
		uint8_t buf[1];
	}MsgInfo;
#pragma pack(pop)

public:
	MsgUserInfo();
	MsgUserInfo(Player *);

	uint8_t *getInfo() { return (uint8_t *)data; }
	uint16_t getSize() { return size; }

private:
	MsgInfo *data;
	uint16_t size;
};