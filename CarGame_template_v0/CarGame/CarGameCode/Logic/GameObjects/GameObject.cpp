//Include
#include "GameObject.h"
#include "../Game.h"

//Metodo para renderizar la textura del objeto 
void GameObject::drawTexture(Texture* texture)
{
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();

    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
};

//Metodo para dibujar el objeto en pantalla si existe
void GameObject::draw()
{
    if (this != nullptr)
        drawTexture(game->getTexture(textureName));
}