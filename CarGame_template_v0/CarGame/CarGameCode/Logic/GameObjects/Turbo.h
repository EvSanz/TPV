#pragma once
#ifndef CARGAME_TURBO_H
#define CARGAME_TURBO_H

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "GoodObject.h"

class Turbo : public GoodObject 
{
public:
    Turbo(Game* game) : GoodObject(game) {};

    ~Turbo() {};

    void draw();
    void drawTexture(Texture* texture);
    void update() {};
    bool receiveCarCollision(Car* car) override;
};


#endif



