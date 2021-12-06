#include "Truck.h"
#include "../Game.h"

void Truck::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(truckTexture));
}

void Truck::update() {
    setPosition(getX() - 0.5, getY());
}

void Truck::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

bool Truck::receiveCarCollision(Car* car) {
    car->powerRemaining();
    car->lessSpeed(0);
    alive = false;
    return true;
}

bool Truck::receiveBulletCollision(Bullet* bullet) {
    bullet->destroyBullet();
    alive = false;
    return true;
}
