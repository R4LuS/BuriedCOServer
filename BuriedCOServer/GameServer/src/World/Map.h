#pragma once

#include "DatabaseLocal/Database/DatabaseLocal.h"

class Map
{
public:
	
	Map();
private:
	QVector<AccountLocal *> accounts;
};