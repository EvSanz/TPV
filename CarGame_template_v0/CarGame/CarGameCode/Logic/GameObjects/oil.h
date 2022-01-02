#pragma once
#ifndef CARGAME_OIL_H
#define CARGAME_OIL_H

class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "BadObject.h"

class oil : public BadObject
{
public:

    oil(Game* game) : BadObject(game) { 
        textureName = oilTexture;
        setDimension(40, 40);
    };

    ~oil() {};

    void update() {};

    bool receiveCarCollision(Car* car) override;
};



#endif

