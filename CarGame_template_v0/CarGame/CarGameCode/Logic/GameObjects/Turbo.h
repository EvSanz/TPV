#pragma once
#ifndef CARGAME_TURBO_H
#define CARGAME_TURBO_H

//Includes
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "GoodObject.h"

class Turbo : public GoodObject 
{

public:

    Turbo(Game* game) : GoodObject(game) {

        //Establecemos la textura del turbo y su tamaño
        textureName = turboTexture;
        setDimension(80, 40);
    };

    ~Turbo() {};

    void update() {};
    bool receiveCarCollision(Car* car) override;
};


#endif



