#pragma once
#include "MapItem.h"

class Player: public MapItem {
private:
	float health_;
	int armor_;
	int damage_;
public:
	Player();
	Player(int x, int y, float health, int armor, int damage, char symbol);

	void setHealth(float health);
	int getHealth() const;

	void setArmor(int armor);
	int getArmor() const;

	void setDamage(int damage);
	int getDamage() const;

	void info() const;
	void move(char key);
	void attack(Player* enemy);
	bool isEnemyAround(Player* enemy);
};

