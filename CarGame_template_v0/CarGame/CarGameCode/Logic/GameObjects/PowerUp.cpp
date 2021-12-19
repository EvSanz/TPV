#include "PowerUp.h"
#include "../Game.h"

bool PowerUp::receiveCarCollision(Car* car) {
    
    car->moreLives();
    alive = false;
    return true;
}