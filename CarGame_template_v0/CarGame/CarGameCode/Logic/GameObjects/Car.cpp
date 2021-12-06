//
// Created by eys on 21/8/21.
//

#include "Car.h"
#include "../Game.h"

void Car::update() {
    setPosition(getX() + HSPEED, getY());
    
    vector<Collider*> collisions = game->con->getCollisions(this);

    for (auto c : collisions) {
        c->receiveCarCollision(this);
    }
    
    if (isSpeed) {
        if (turboCounter >= 150) {
            isSpeed = false;
            HSPEED = 10;
        }
        turboCounter++;
    }
}

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
        if (HSPEED >= 1) {
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

void Car::shootBullet()
{
    if (coins > 0)
        coins--;
}

void Car::lessSpeed(double retardo)
{
    if (HSPEED > 0)
    {
        HSPEED = HSPEED * retardo; 

        if (HSPEED <= 0.1)
            HSPEED = 0.1; 
    }

    else
        HSPEED = 0.1;
}

void Car::moreSpeed() 
{
    HSPEED = 20;
    isSpeed = true;
    turboCounter = 0;
}