#pragma once
#ifndef CARGAME_TRUCK_H
#define CARGAME_TRUCK_H

class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "Obstacles.h"

class Truck : public Obstacle
{
public:

    Truck(Game* game) : Obstacle(game) { };

    ~Truck() {
    };

    void draw();
    void update();
};



#endif

