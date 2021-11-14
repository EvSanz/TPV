#include "PowerUp.h"
#include "../Game.h"

void PowerUp::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(powerUpTexture));
}

void PowerUp::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

bool PowerUp::receiveCarCollision(Car* car) {
    car->moreLives();
    alive = false;
    return true;
}