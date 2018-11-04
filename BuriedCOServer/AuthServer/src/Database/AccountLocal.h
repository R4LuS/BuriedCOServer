#pragma once

#include <QObject>
#include <QFile>

#include "CharacterLocal.h"

class AccountLocal 
{
public:
	AccountLocal();
	AccountLocal(QByteArray username, QByteArray password, uint32_t uniqueID);

	void loadCharacter(QString characterFile);

public:
	QByteArray getUsername() { return username; }
	QByteArray getPassword() { return password; }
	uint32_t getUniqueID() { return uniqueID; }

private:
	QByteArray username;
	QByteArray password;
	uint32_t uniqueID;
	CharacterLocal *character;
};