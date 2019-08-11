#pragma once

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QDate>
#include "AccountLocal.h"
#include "MsgPackets/Msg/MsgDate.h"

class DatabaseLocal
{
	
public:
	DatabaseLocal();

	void loadAccounts(QString accountFile);
	void loadNpcs(QString npcsFile);

	bool validAccount(QByteArray username, QByteArray password);
	AccountLocal *getByName(QByteArray username);
	AccountLocal *getByID(uint32_t);
	static MsgDate::Date getDate();

private:
	QList<AccountLocal *> accounts;
};