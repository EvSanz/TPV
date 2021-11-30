#include "Turbo.h"
#include "../Game.h"

void Turbo::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(turboTexture));
}

void Turbo::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

bool Turbo::receiveCarCollision(Car* car) {

    car->moreSpeed();
    return true;
}

