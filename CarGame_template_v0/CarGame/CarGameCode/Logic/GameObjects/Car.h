//
// Created by eys on 21/8/21.
//

#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H


class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"

class Car {

private:

    const double ACCELERATION = 1.3;
    const double DECELERATION = 0.9;
    const int VSPEED = 5;
    const int MAX_SPEED = 10;
    const int INITIAL_POWER = 3; //esto son las vidas
    double HSPEED = 1;

    Point2D<double> pos;
    int w, h, power = INITIAL_POWER;
    Game *game;
    Texture *texture;


public:
    Car(Game *game);
    ~Car();

    void draw();
    void update();
    void drawTexture(Texture* texture);

    void setDimension(int width, int height);

    double getX() {return pos.getX();};
    double getY() {return pos.getY();};
    int getWidth() {return w;};
    int getHeight() {return h;};
    int getPower() { return power; };

    void setPosition(double x, double y);

    SDL_Rect getCollider();

    void speedControl(bool accelerate);
    void verticalmove(bool lTurn);

    bool isAlive(int power) { return power > -1; }
    void powerRemaining(int power);

    void resetValor();
};


#endif //CARGAME_CAR_H
