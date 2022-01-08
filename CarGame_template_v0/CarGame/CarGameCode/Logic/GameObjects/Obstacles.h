#pragma once
#ifndef CARGAME_OBSTACLES_H
#define CARGAME_OBSTACLES_H

//Includes
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "BadObject.h"

//Clases
class Game;

class Obstacle: public BadObject {

public:
    
    Obstacle(Game* game) : BadObject(game) {

        //Establecemos la textura del obstaculo y su tamaño
        textureName = rockTexture;
        setDimension(50, 50);
    };

    ~Obstacle() {};

    void update() {}; 

    bool receiveCarCollision(Car* car) override;
    bool receiveBulletCollision(Bullet* bullet) override;
};




#endif

