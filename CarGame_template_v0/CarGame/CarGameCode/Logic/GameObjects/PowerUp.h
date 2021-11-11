#pragma once
#ifndef CARGAME_POWERUP_H
#define CARGAME_POWERUP_H

class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"
//aun no hace nada esta clase ya que no esta metida en la partida
//acordarse de meter que si lo toca el coche se sube la vida
class PowerUp : public GameObject {

public:
    PowerUp(Game* game) : GameObject(game) {};
    ~PowerUp() {};

    void draw();
    void drawTexture(Texture* texture);
    void update() {};
};

#endif