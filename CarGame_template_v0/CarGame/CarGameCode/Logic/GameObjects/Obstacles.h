#pragma once

#ifndef CARGAME_OBSTACLES_H
#define CARGAME_OBSTACLES_H


class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"

class Obstacle {

private:

    int value = 1;

    Point2D<double> pos;
    int w, h;
    Game* game;
    Texture* texture;

public:
    Obstacle(Game* game);
    ~Obstacle();

    void draw();
    void drawTexture(Texture* texture);

    void setDimension(int width, int height);

    double getX() { return pos.getX(); };
    double getY() { return pos.getY(); };
    int getWidth() { return w; };
    int getHeight() { return h; };

    void setPosition(double x, double y);

    SDL_Rect getCollider();

    bool isAlive() { return value > 0; }
    void destroy();
    void free() {
        texture->free();
    }
};


#endif

