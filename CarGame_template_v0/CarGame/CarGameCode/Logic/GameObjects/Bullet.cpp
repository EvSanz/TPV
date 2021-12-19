#include "Bullet.h"
#include "../Game.h"

void Bullet::update() {

    setPosition(getX() + HSPEED, getY());

    vector<Collider*> collisions = game->con->getCollisions(this);

    for (auto c: collisions) {
        c->receiveBulletCollision(this); 
    }
}

bool Bullet::toDelete()
{
    return !vida; 
}

