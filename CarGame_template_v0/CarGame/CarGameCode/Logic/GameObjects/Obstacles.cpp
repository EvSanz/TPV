#include "Obstacles.h"
#include "../Game.h"


bool Obstacle::receiveCarCollision(Car* car) {
    car->powerRemaining();
    alive = false;
    return true;
}

bool Obstacle::receiveBulletCollision(Bullet* bullet) {
    alive = false;
    return true;
}

