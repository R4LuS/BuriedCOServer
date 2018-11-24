#pragma once

#include <QObject>
#include <QFile>
#include <QDebug>

#include "AccountLocal.h"

class DatabaseLocal
{
public:
	DatabaseLocal();
	void loadAccounts(QString accountFile);
	void loadNpcs(QString npcsFile);

	bool validAccount(QByteArray username, QByteArray password);
	AccountLocal *getByName(QByteArray username);
	AccountLocal *getByID(uint32_t);

private:
	QList<AccountLocal *> accounts;
};