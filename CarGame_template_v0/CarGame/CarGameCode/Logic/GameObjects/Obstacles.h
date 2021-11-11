#pragma once

#ifndef CARGAME_OBSTACLES_H
#define CARGAME_OBSTACLES_H


class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

class Obstacle: public GameObject {



public:
    
    Obstacle(Game* game) : GameObject(game) 
    {
        GameObject::setBool(false);
    };

    ~Obstacle() {};

    void draw();
    void drawTexture(Texture* texture);
    void update() {}; 
};




#endif

