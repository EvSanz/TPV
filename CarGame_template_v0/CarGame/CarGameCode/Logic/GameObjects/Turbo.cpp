//Includes
#include "Turbo.h"
#include "../Game.h"

bool Turbo::receiveCarCollision(Car* car) {
    //Si recibimos colision con el coche, aumentamos su velocidad
    car->moreSpeed();
    return true;
}

