#ifndef CARGAME_BULLET_H
#define CARGAME_BULLET_H

class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

class Bullet : public GameObject {
private:
    const int HSPEED = 15;

public:
    Bullet(Game* game) : GameObject(game) {};

    ~Bullet() {};

    void draw();
    void drawTexture(Texture* texture);
    void update();
    
};

#endif



