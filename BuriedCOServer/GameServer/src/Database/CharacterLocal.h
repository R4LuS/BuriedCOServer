#pragma once

#include <QObject>

class CharacterLocal
{
public:
	CharacterLocal(QByteArray nickname, uint16_t model, uint16_t cClass);

public:
	QByteArray getNickname() { return nickname; }
	uint16_t getLevel() { return level; }
	uint16_t getModel() { return model; }
	uint16_t getClass() { return cClass; }
	uint16_t getStrength() { return strength; }
	uint16_t getDexterity() { return dexterity; }
	uint16_t getHealth() { return health; }
	uint16_t getSoul() { return soul; }
	uint16_t getLife() { return life; }
	uint16_t getMana() { return mana; }


private:
	QByteArray nickname;
	uint16_t level;
	uint16_t model;
	uint16_t cClass;
	uint16_t strength;
	uint16_t dexterity;
	uint16_t health;
	uint16_t soul;
	uint16_t life;
	uint16_t mana;
	uint16_t mapID;
	uint16_t 
};