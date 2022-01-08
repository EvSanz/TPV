//Includes
#include "oil.h"
#include "../Game.h"

bool oil::receiveCarCollision(Car* car) {
    //Si ha detectado colision con un coche, disminuimos su velocidad
    car->lessSpeed(0.7); 
    return true;
}


