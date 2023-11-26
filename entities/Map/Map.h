#pragma once
#include "const.h"
#include "MapItem.h"

class Map {
private:
	char map_[map_config::mapHeight][map_config::mapWidth];
	MapItem* mapItems_[map_config::mapMaxItems];
	int filled_;
public:
	Map();
	void addMapItem(MapItem* item);
	void draw();
};

 