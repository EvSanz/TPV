#pragma once
#ifndef CARGAME_COIN_H
#define CARGAME_COIN_H

//Includes
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "GoodObject.h"

class Coin : public GoodObject {

public:
    Coin(Game* game) : GoodObject(game) {
        
        //Establecemos el tamaño y la textura
        textureName = coinTexture;
        setDimension(20, 20);
    };

    ~Coin() {};

    void update() {};
    bool receiveCarCollision(Car* car) override;
};

#endif

