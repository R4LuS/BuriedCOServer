#pragma once

#include <QObject>
#include "Map.h"

class World
{
public:
	
	World();

	void loadMaps(const char *);
private:
	QMap<int, Map *> aMaps;
};