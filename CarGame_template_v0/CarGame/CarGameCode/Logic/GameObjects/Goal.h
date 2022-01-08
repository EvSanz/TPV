#pragma once
#ifndef CARGAME_GOAL_H
#define CARGAME_GOAL_H

//Includes
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

//Clases
class Game;

class Goal: public GameObject {

public:

    Goal(Game* game) : GameObject(game) {};
    ~Goal() {};

    void update() {};
};


#endif


