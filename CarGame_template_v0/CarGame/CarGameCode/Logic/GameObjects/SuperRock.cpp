#include "SuperRock.h"
#include "../Game.h"

bool SuperRock::receiveCarCollision(Car* car) {
    car->powerRemaining();
    car->powerRemaining();
    alive = false;
    return true;
}

bool SuperRock::receiveBulletCollision(Bullet* bullet) {
    return true;
}