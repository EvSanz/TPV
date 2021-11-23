#include "Obstacles.h"
#include "../Game.h"

void Obstacle::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(rockTexture));
}

void Obstacle::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

bool Obstacle::receiveCarCollision(Car* car) {
    car->powerRemaining();
    alive = false;
    return true;
}

bool Obstacle::receiveBulletCollision(Bullet* bullet) {
    bullet->destroyBullet(); 
    alive = false;
    return true;
}

