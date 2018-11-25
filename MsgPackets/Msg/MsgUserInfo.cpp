
#include "MsgUserInfo.h"
#include "ThirdParty/third/stringpacker.h"

MsgUserInfo::MsgUserInfo() :
	Msg()
{
	size = sizeof(MsgInfo) + strlen("Test") + 1 + strlen("None") + 1;
	data = (MsgInfo *)new uint8_t[size];
	data->header.packetSize = size;
	data->header.packetID = 1006;
	data->id = 10000;
	data->mesh = 1003;
	data->hairstyle = 535;
	data->silver = 10000;
	data->cps = 10000;
	data->experience = 1;
	data->strength = 5;
	data->agility = 5;
	data->vitality = 5;
	data->spirit = 5;
	data->extraPoints = 0;
	data->health = 1000;
	data->mana = 1000;
	data->pkpoints = 0;
	data->level = 1;
	data->cclass = 10;
	data->pclass = 0;
	data->rebirth = 0;
	data->showname = 1;

	memset(data->padding, 0, sizeof(data->padding));
	data->buf[0] = 0;
	StringPacker packer(data->buf);
	packer.addString("Test");
	packer.addString("None");
}

MsgUserInfo::MsgUserInfo(Player *player) :
	Msg()
{
	
}