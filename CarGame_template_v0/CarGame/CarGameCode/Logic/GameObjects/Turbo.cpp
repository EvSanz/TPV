#include "Turbo.h"
#include "../Game.h"

bool Turbo::receiveCarCollision(Car* car) {

    car->moreSpeed();
    return true;
}

