#include "Coin.h"
#include "../Game.h"

void Coin::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(coinTexture));
}

void Coin::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

bool Coin::receiveCarCollision(Car* car) {

    car->moreCoins();
    alive = false;
    return true;
}
