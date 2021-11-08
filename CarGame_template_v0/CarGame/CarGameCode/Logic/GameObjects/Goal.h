#pragma once

#pragma once

#ifndef CARGAME_GOAL_H
#define CARGAME_GOAL_H

class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

class Goal: public GameObject {

public:
    Goal(Game* game) : GameObject(game) {};
    ~Goal() {};

    void draw();
    void drawTexture(Texture* texture);
    void update() {};
};


#endif


