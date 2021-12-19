#pragma once

#ifndef CARGAME_SUPERROCK_H
#define CARGAME_SUPERROCK_H

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "BadObject.h"

class SuperRock :  public BadObject {

public:

    SuperRock(Game* game) : BadObject(game) {
        textureName = superRockTexture;
        setDimension(160, 80);
    };

    ~SuperRock() {};

    void update() {};

    bool receiveCarCollision(Car* car) override;
    bool receiveBulletCollision(Bullet* bullet) override;
};


#endif