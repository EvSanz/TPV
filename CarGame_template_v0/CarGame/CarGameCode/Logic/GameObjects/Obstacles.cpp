#include "Obstacles.h"
#include "../Game.h"

Obstacle::Obstacle(Game* game) {
    this->game = game;
    texture = nullptr;
}

void Obstacle::setDimension(int width, int height) {
    w = width;
    h = height;
};

void Obstacle::setPosition(double x, double y) {
    pos = Point2D<double>(x, y);
};

Obstacle::~Obstacle() {};

void Obstacle::draw() {
    drawTexture(game->getTexture(rockTexture));
}


void Obstacle::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}


SDL_Rect Obstacle::getCollider() {
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
}

void Obstacle::destroy()
{
    if (isAlive())
        value = 0;
}