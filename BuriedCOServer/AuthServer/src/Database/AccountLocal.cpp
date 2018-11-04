
#include "AccountLocal.h"


AccountLocal::AccountLocal() 
{
}

AccountLocal::AccountLocal(QByteArray username, QByteArray password, uint32_t uniqueID) :
	username(username), password(password), uniqueID(uniqueID)
{
}

void AccountLocal::loadCharacter(QString characterFile)
{
	QFile cFile("database/Characters/" + characterFile);
	if (cFile.exists()) {
		cFile.open(QIODevice::ReadOnly | QIODevice::Text);


		cFile.close();
	}
}