#ifndef CARGAME_BULLET_H
#define CARGAME_BULLET_H

//Includes
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

//Clases 
class Game;

class Bullet : public GameObject {

protected: 

    //Booleano de estado actual 
    bool vida;

private:

    //Velocidad de movimiento 
    const int HSPEED = 15;

public:

    Bullet(Game* game) : GameObject(game)  
    {
        //Establecemos que existe, su textura y tamaño
        vida = true; 
        textureName = bulletTexture;
        setDimension(20, 5);
    };

    ~Bullet() {};

    void update();
    bool toDelete() override; 
};
 
#endif



