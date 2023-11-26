#include "Apple.h"
#include "MapItem.h"

Apple::Apple(int x, int y, float health, char symbol):
	MapItem(x, y, symbol), health_(health) {}


int Apple::getHealth() const {
	return this->health_;
}
