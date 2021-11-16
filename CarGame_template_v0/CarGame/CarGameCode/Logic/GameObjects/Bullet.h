#pragma once
#ifndef CARGAME_BULLET_H
#define CARGAME_BULLET_H

class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "GoodObject.h"

class Bullet : public GoodObject {

public:
    Bullet(Game* game) : GoodObject(game) {};

    ~Bullet() {};

    void draw();
    void drawTexture(Texture* texture);
    void update() {};
    bool receiveCarCollision(Car* car) override;
};

#endif



