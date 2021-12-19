#include "GameObject.h"
#include "../Game.h"

void GameObject::drawTexture(Texture* texture)
{
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
};

void GameObject::draw()
{
    if (this != nullptr)
        drawTexture(game->getTexture(textureName));
}