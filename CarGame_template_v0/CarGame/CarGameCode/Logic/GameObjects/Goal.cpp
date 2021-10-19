#include "Goal.h"
#include "../Game.h"

Goal::Goal(Game* game) {
    this->game = game;
    texture = nullptr;
}

void Goal::setDimension(int width, int height) {
    w = width;
    h = height;
};

void Goal::setPosition(double x, double y) {
    pos = Point2D<double>(x, y);
};

Goal::~Goal() {};

void Goal::draw() {
    if (this != nullptr)
        drawTexture(game->getTexture(goalTexture));
}

void Goal::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

SDL_Rect Goal::getCollider() {
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
}
