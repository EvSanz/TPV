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
    Goal(Game* game) : GameObject(game) {
        cout << "Goal constructor: " << endl;
    };
    ~Goal() {
        cout << "Goal destructor" << endl;
    };

    void update() {};
};


#endif


