//
// Created by eys on 21/8/21.
//

#include "Car.h"
#include "../Game.h"

Car::Car(Game *game){
    this->game = game;
    texture = nullptr;

}

void Car::setDimension(int width, int height){
    w = width;
    h = height;
};

void  Car::setPosition(double x, double y){
    pos = Point2D<double>(x, y);
};

void Car::update() {
    pos = Point2D<double>(getX() + HSPEED, getY());
}

Car::~Car(){};

void Car::draw() {
    drawTexture(game->getTexture(carTexture));
}


void Car::drawTexture(Texture *texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h};
    texture->render(textureBox);
}

SDL_Rect Car::getCollider(){
    return { int(getX() - getWidth()),
             int(getY() - getHeight()/2),
             getWidth(),
             getHeight()};
}

void Car::speedControl(bool accelerate) {
    if (isAlive())
    {
        if (accelerate) {
            HSPEED = HSPEED * ACCELERATION;

            if (HSPEED > 10) {
                HSPEED = 10;
            }
        }
        else {
            HSPEED = HSPEED * DECELERATION;
        }
    }

    else
        HSPEED = 0;
}

void Car::verticalmove(bool lTurn) {
    if (isAlive())
    {
        if (lTurn) {
            setPosition(getX(), getY() - VSPEED);
            if (getY() < getHeight() / 2)
                setPosition(getX(), getHeight() / 2);
        }
        else {
            setPosition(getX(), getY() + VSPEED);
            if (getY() > game->getWindowHeight() - getHeight() / 2)
                setPosition(getX(), game->getWindowHeight() - getHeight() / 2);
        }
    }

    else
        setPosition(getX(), getY());
}

void Car::powerRemaining()
{
    if (isAlive())
    {
        HSPEED = 0.1; 
        power--;
    }
}

void Car::resetValor()
{
    HSPEED = 1;
    power = INITIAL_POWER;
    setPosition(getWidth(), game->getWindowHeight() / 2.0); 
}