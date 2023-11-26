#include <iostream>
#include <conio.h>
#include "Game.h"
#include "Utils.h"

using namespace std;

// Constructor
Game::Game():
	player_(Player{ 3,3,100,100,100, 'P' }),
	enemy_(Player{ 5,5,100,100,100, 'E' }),
	apple_(Apple{ 10,10,100, '*' }),
	map_() {}

void Game::run() {
	char playerAction;
	char enemyAction;

	this->map_.addMapItem(&this->player_);
	this->map_.addMapItem(&this->enemy_);
	this->map_.addMapItem(&this->apple_);

	do {
		system("cls");
		this->player_.info();
		this->enemy_.info();
		this->map_.draw();

		cout << "Please enter direction(w, a, s, d): ";

		playerAction = _getch();
		enemyAction = Utils::getRandomAction();

		if (playerAction == 'r') {
			this->player_.attack(&this->enemy_);
		}

		if (enemyAction == 'r') {
			this->enemy_.attack(&this->player_);
		}

		this->player_.move(playerAction);
		this->enemy_.move(enemyAction);
	}
	while (playerAction != 'q');
}
