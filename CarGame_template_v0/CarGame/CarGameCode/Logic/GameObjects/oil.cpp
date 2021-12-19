#include "oil.h"
#include "../Game.h"

bool oil::receiveCarCollision(Car* car) {
    car->lessSpeed(0.7); 
    return true;
}


