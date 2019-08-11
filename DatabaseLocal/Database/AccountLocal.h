#pragma once

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDate>
#include "CharacterLocal.h"

class AccountLocal 
{
public:
	AccountLocal();
	AccountLocal(QByteArray username, QByteArray password, uint32_t uniqueID);

	void loadCharacter(QString characterFile);
	void createCharacter(QByteArray nickname, uint16_t model, uint16_t cClass);

public:
	QByteArray getUsername() { return username; }
	QByteArray getPassword() { return password; }
	uint32_t getUniqueID() { return uniqueID; }
	CharacterLocal *getCharacter() { return character; }

private:
	QByteArray username;
	QByteArray password;
	uint32_t uniqueID;
	CharacterLocal *character;
};