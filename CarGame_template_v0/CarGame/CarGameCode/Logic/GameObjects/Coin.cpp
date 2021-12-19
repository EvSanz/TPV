#include "Coin.h"
#include "../Game.h"

bool Coin::receiveCarCollision(Car* car) {

    car->moreCoins();
    alive = false;
    return true;
}
