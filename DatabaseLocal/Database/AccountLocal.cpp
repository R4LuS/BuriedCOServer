
#include "AccountLocal.h"


AccountLocal::AccountLocal() 
{
}

AccountLocal::AccountLocal(QByteArray username, QByteArray password, uint32_t uniqueID) :
	username(username), password(password), uniqueID(uniqueID)
{
	character = nullptr;
}

void AccountLocal::loadCharacter(QString characterFile)
{
	QFile cFile("database/Characters/" + characterFile);
	if (cFile.exists()) {
		cFile.open(QIODevice::ReadOnly | QIODevice::Text);


		cFile.close();
	}
}

void AccountLocal::createCharacter(QByteArray nickname, uint16_t model, uint16_t cClass)
{
	character = new CharacterLocal(nickname, model, cClass);
}