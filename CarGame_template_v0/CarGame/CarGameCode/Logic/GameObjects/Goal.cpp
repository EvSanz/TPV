#include "Goal.h"
#include "../Game.h"

void Goal::draw() {
    drawTexture(game->getTexture(goalTexture));
}

void Goal::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

