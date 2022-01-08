//Includes
#include "SuperRock.h"
#include "../Game.h"

bool SuperRock::receiveCarCollision(Car* car) {

    //Si ha detectado colision con un coche, perdemos vidas
    //y destruimos el obstaculo
    car->powerRemaining(2);
    alive = false;
    return true;
}

bool SuperRock::receiveBulletCollision(Bullet* bullet) {

    //Si detecta colision con una bala, no hace nada
    return true;
}