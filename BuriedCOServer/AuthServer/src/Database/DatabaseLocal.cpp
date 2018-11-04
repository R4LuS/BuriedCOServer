
#include "DatabaseLocal.h"


DatabaseLocal::DatabaseLocal()
{
}


void DatabaseLocal::loadAccounts(QString accountsFile)
{
	int nAccounts = 0;
	fprintf(stdout, "Loading accounts... ");
	QFile accountFile("database/" + accountsFile);
	if (!accountFile.exists()) {
		fprintf(stdout, "File: %s was not found...\n", accountsFile.toStdString().c_str());
		return;
	}
	else {

	}
	accountFile.open(QIODevice::ReadOnly | QIODevice::Text);

	while (!accountFile.atEnd()) {
		QByteArray line = accountFile.readLine();
		QList<QByteArray> accountData = line.split(';');
		AccountLocal *newAccount = new AccountLocal(accountData.at(0), accountData.at(1), atoi(accountData.at(2).data()));
		//newAccount->loadCharacter(QString::fromStdString(accountData.at(2).toStdString()));
		accounts.append(newAccount);
		nAccounts++;
	}

	accountFile.close();
	fprintf(stdout, " [DONE:%d].\n", nAccounts);
}

void DatabaseLocal::loadNpcs(QString npcsFile)
{

}


bool DatabaseLocal::validAccount(QByteArray username, QByteArray password) 
{
	for (AccountLocal *al : accounts) {
		if (al->getUsername() == username && al->getPassword() == password) {
			return true;
		}
	}
	return false;
}

AccountLocal *DatabaseLocal::getByName(QByteArray username) 
{
	for (AccountLocal *al : accounts) {
		if (al->getUsername() == username) {
			return al;
		}
	}
	return nullptr;
}