//
// Created by eys on 21/8/21.
//

#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H


class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

class Car : public GameObject {

private:

    const double ACCELERATION = 1.3;
    const double DECELERATION = 0.9;
    const int VSPEED = 5;
    const int MAX_SPEED = 10;
    const int INITIAL_POWER = 3; //esto son las vidas
    double HSPEED = 1;

    //Point2D<double> pos;
    //int w, h; 
    int power = INITIAL_POWER;
    //Game *game;
    //Texture *texture;


public:
    Car(Game* game) : GameObject(game) {
        //texture = nullptr;
    };
    ~Car();

    void draw();
    void update();
    void drawTexture(Texture* texture);

    
    int getPower() { return power; };
    int getSpeed() { return HSPEED; };


    void speedControl(bool accelerate);
    void verticalmove(bool lTurn);

    bool isAlive() { return power > 0; }
    void powerRemaining();

    void resetValor();
};


#endif //CARGAME_CAR_H
