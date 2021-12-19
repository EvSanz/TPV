#pragma once

#ifndef CARGAME_OBSTACLES_H
#define CARGAME_OBSTACLES_H


class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
#include "BadObject.h"

class Obstacle: public BadObject {

public:
    
    Obstacle(Game* game) : BadObject(game) {
        //id = instances;
        //cout << "Rock constructor: " << id << endl;
    };

    ~Obstacle() {
        //cout << "Rock destructor: " << id << endl;
    };

    void update() {}; 

    bool receiveCarCollision(Car* car) override;
    bool receiveBulletCollision(Bullet* bullet) override;
};




#endif

