#ifndef CARGAME_BULLET_H
#define CARGAME_BULLET_H

class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

class Bullet : public GameObject {

protected: 
    bool vida;
private:
    const int HSPEED = 15;
public:
    Bullet(Game* game) : GameObject(game)  
    {
        vida = true; 
    };

    ~Bullet() {

    };

    void draw();
    void drawTexture(Texture* texture);
    void update();

    void destroyBullet() { vida = false; }

    bool toDelete() override; 
};
 
#endif



