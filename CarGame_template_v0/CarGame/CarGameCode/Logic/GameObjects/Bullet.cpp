#include "Bullet.h"
#include "../Game.h"

void Bullet::update() {

    setPosition(getX() + HSPEED, getY());

    vector<Collider*> collisions = game->con->getCollisions(this);

    for (auto c: collisions) {
        //si un objeto recibe colision de bala y devuelve true se borra la bala
        if(c->receiveBulletCollision(this)) 
            vida = false;
    }
}

bool Bullet::toDelete()
{
    return !vida; 
}

