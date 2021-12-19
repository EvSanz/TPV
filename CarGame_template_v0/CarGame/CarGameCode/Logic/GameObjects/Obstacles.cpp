#include "Obstacles.h"
#include "../Game.h"


bool Obstacle::receiveCarCollision(Car* car) {
    car->powerRemaining();
    alive = false;
    return true;
}

bool Obstacle::receiveBulletCollision(Bullet* bullet) {
    bullet->destroyBullet(); 
    alive = false;
    return true;
}

