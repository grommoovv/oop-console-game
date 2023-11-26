#include <iostream>
#include "Player.h"
#include "MapItem.h"
#include "const.h"

using namespace std;

// Constructor
Player::Player(): MapItem(0, 0, 'P'), health_(0), armor_(0), damage_(0) {}

Player::Player(int x, int y, float health, int armor, int damage, char symbol):
	MapItem(x, y, symbol), health_(health), armor_(armor), damage_(damage) {}

void Player::setHealth(float health) {
	if (this->health_ == 0) {
		return;
	}
	if ((this->health_ - health) < 0) {
		this->health_ = 0;
	}
	this->health_ = health;
}

int Player::getHealth() const {
	return this->health_;
}

void Player::setArmor(int armor) {
	this->armor_ = armor;
}

int Player::getArmor() const {
	return this->armor_;
}

void Player::setDamage(int damage) {
	this->damage_ = damage;
}

int Player::getDamage() const {
	return this->damage_;
}

void Player::info() const {
	cout << "***** Player Info: " << this << " *****" << endl;
	cout << "X: " << this->x_ << endl;
	cout << "Y: " << this->y_ << endl;
	cout << "HEALTH: " << this->health_ << endl;
	cout << "ARMOR: " << this->armor_ << endl;
	cout << "DAMAGE: " << this->damage_ << endl;
	cout << "*****************************************" << endl;
}

void Player::move(char key) {
	if (this->x_ > 1 && key == 'w') this->x_--;

	if (this->x_ < (map_config::mapHeight - 2) && key == 's') this->x_++;

	if (this->y_ > 1 && key == 'a') this->y_--;

	if (this->y_ < (map_config::mapWidth - 2) && key == 'd') this->y_++;
}

void Player::attack(Player* enemy) {

	if (!this->isEnemyAround(enemy)) {
		return;
	}

	float health = enemy->getHealth();

	float damageRatio = static_cast<float>(this->damage_) * 40 / 100;
	float armorRatio = static_cast<float>(enemy->getArmor()) * 20 / 100;

	float decreaseHealth = damageRatio - armorRatio;

	if (decreaseHealth <= 0) {
		decreaseHealth = 1;
	}

	health -= decreaseHealth;
	enemy->setHealth(health);
}

bool Player::isEnemyAround(Player* enemy) {
	return (this->x_ - 1 == enemy->getX() || this->x_ == enemy->getX() || this->x_ + 1 == enemy->getX()) &&
		(this->y_ - 1 == enemy->getY() || this->y_ == enemy->getY() || this->y_ + 1 == enemy->getY());
}
