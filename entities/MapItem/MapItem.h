#pragma once
class MapItem {
protected: 
	int x_; 
	int y_; 
	char symbol_;
public:
	MapItem(int x, int y, char symbol);
	int getX() const;
	int getY() const;
	char getSymbol() const;
};

