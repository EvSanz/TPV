#include "SuperRock.h"
#include "../Game.h"

void SuperRock::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(superRockTexture));
}

void SuperRock::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

bool SuperRock::receiveCarCollision(Car* car) {
    car->powerRemaining();
    car->powerRemaining();
    alive = false;
    return true;
}

bool SuperRock::receiveBulletCollision(Bullet* bullet) {
    bullet->destroyBullet();
    return true;
}