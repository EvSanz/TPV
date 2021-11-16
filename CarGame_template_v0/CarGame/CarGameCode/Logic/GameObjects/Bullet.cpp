#include "Bullet.h"
#include "../Game.h"

void Bullet::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(bulletTexture));
}

void Bullet::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

bool Bullet::receiveCarCollision(Car* car) {

    car->moreLives();
    alive = false;
    return true;
}
