#pragma once
#ifndef CARGAME_TRUCK_H
#define CARGAME_TRUCK_H

//Includes
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "Obstacles.h"

//Clases
class Game;

class Truck : public Obstacle
{
public:

    Truck(Game* game) : Obstacle(game) { 

        //Establecemos la textura del camion y su tamaño
        textureName = truckTexture;
        setDimension(120, 60);
    };

    ~Truck() {};

    void update();
};



#endif

