#include "Truck.h"
#include "../Game.h"

void Truck::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(truckTexture));
}

void Truck::update() {
    setPosition(getX() - 0.5, getY());
}

