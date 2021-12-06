#pragma once
#ifndef CARGAME_TRUCK_H
#define CARGAME_TRUCK_H

class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "BadObject.h"

class Truck : public BadObject
{
public:

    Truck(Game* game) : BadObject(game) { };

    ~Truck() {
    };

    void draw();
    void drawTexture(Texture* texture);
    void update();

    bool receiveCarCollision(Car* car) override;
    bool receiveBulletCollision(Bullet* bullet) override;
};



#endif

