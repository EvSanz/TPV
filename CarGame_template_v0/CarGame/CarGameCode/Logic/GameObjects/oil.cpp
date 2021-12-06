#include "oil.h"
#include "../Game.h"

void oil::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(oilTexture));
}

void oil::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

bool oil::receiveCarCollision(Car* car) {
    car->lessSpeed(0.7); 
    return true;
}

