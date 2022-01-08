//Includes
#include "Bullet.h"
#include "../Game.h"

void Bullet::update() {

    //Cambiamos la posicion del objeto 
    setPosition(getX() + HSPEED, getY());

    //Creamos un vector donde guardamos las colisiones que 
    //se han detectado
    vector<Collider*> collisions = game->con->getCollisions(this);

    //Comprobamos todas las colisiones que han sucedido
    for (auto c: collisions) {

        //Si un objeto ha recibido la colision de una bala, borramos esta
        if(c->receiveBulletCollision(this)) 
            vida = false;
    }
}

//Metodo para devolver el estado actual de la bala
bool Bullet::toDelete()
{
    return !vida; 
}

