#include "Utils.h"
#include <ctime>
#include <stdlib.h>

char Utils::getRandomAction(){
    srand(time(nullptr));
    int randomIndex = rand() % 5;
    char enemyActions[] = { 'w', 's', 'a', 'd', 'r' };
    return enemyActions[randomIndex];
}
