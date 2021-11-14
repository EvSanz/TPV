#pragma once
#ifndef CARGAME_POWERUP_H
#define CARGAME_POWERUP_H

class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "GoodObject.h"

class PowerUp : public GoodObject {

public:
    PowerUp(Game* game) : GoodObject(game){};

    ~PowerUp() {};

    void draw();
    void drawTexture(Texture* texture);
    void update() {};
};

#endif