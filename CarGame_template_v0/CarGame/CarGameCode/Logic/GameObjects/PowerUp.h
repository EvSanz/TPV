#pragma once
#ifndef CARGAME_POWERUP_H
#define CARGAME_POWERUP_H

//Include
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "GoodObject.h"

//Clase
class Game;

class PowerUp : public GoodObject {

public:

    PowerUp(Game* game) : GoodObject(game){

        //Establecemos la textura del powerUp y su tama?o
        textureName = powerUpTexture;
        setDimension(40, 40);
    };

    ~PowerUp() {};

    void update() {};

    bool receiveCarCollision(Car* car) override;
};

#endif