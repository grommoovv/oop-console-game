#include <iostream>
#include "Map.h"
#include "MapItem.h"
#include "const.h"

using namespace std;

// Constructor
Map::Map(): filled_(0) {

	for (int i = 0; i < map_config::mapMaxItems; i++) {
		this->mapItems_[i] = nullptr;
	}

	for (int i = 0; i < map_config::mapHeight; i++) {
		for (int j = 0; j < map_config::mapWidth; j++) {
			if (i == 0 || i == map_config::mapHeight - 1 || j == 0 || j == map_config::mapWidth - 1) {
				map_[i][j] = '#';
			} else {
				map_[i][j] = ' ';
			}
		}
	}
}

void Map::addMapItem(MapItem* item) {
	this->mapItems_[this->filled_] = item;
	this->filled_++;
}

void Map::draw() {
	for (int i = 0; i < map_config::mapHeight; i++) {
		for (int j = 0; j < map_config::mapWidth; j++) {

			bool isDraw = false;

			for (int k = 0; k < this->filled_; k++) {
				MapItem* currentItem = this->mapItems_[k];

				if (currentItem == nullptr) {
					continue;
				}

				if (!isDraw && currentItem->getX() == i && currentItem->getY() == j) {
					cout << currentItem->getSymbol();
					isDraw = true;
				}
			}

			if (!isDraw) {
				cout << map_[i][j];
			}
		}
		cout << endl;
	}
}


