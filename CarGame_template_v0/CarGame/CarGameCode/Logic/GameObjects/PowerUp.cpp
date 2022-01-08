//Includes
#include "PowerUp.h"
#include "../Game.h"

bool PowerUp::receiveCarCollision(Car* car) {
    
    //Si ha detectado colision con un coche, aumentamos la vida
    //del jugador y destruimos el powerUp
    car->moreLives();
    alive = false;
    return true;
}