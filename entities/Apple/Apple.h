#pragma once
#include "Player.h"
#include "MapItem.h"

class Apple: public MapItem {
private:
	float health_;
public:
	Apple(int x, int y, float health, char symbol);

	int getHealth() const;
};

