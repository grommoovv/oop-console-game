#include "MapItem.h"

MapItem::MapItem(int x, int y, char symbol): x_(x), y_(y), symbol_(symbol) {}

int MapItem::getX() const {
	return this->x_;
}

int MapItem::getY() const {
	return this->y_;
}

char MapItem::getSymbol() const {
	return this->symbol_;
}
