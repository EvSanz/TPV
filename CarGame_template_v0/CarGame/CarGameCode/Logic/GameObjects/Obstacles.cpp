//Include
#include "Obstacles.h"
#include "../Game.h"

bool Obstacle::receiveCarCollision(Car* car) {
    //Si ha detectado colision con un coche, restamos vida 
    //al coche y destruimos el obstaculo
    car->powerRemaining(1);
    alive = false;
    return true;
}

bool Obstacle::receiveBulletCollision(Bullet* bullet) {
    //Si ha detectado colision con una bala, destruimos el obstaculo
    alive = false;
    return true;
}

