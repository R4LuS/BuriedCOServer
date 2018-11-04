#pragma once

#include "Common/common.h"

class Player 
{
public:
	Player(uint32_t);

private:
	uint32_t id;
	uint32_t mesh;
	uint16_t hairstyle;
	uint32_t silver;
	uint32_t cps;
	uint64_t experience;
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

};