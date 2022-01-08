#ifndef CARGAME_COLLIDER_H
#define CARGAME_COLLIDER_H

//Clases
class Car;
class Bullet;

class Collider {

public:

    //Metodo para detectar si ha habido colision con el coche
    virtual bool receiveCarCollision(Car *car){
        return false;
    };

    //Metodo para detectar si ha habido colision con la bala
    virtual bool receiveBulletCollision(Bullet *bullet) {
        return false;
    };

    //Metodo para hacer el desplazamiento de la ola 
    virtual bool wave(int value = 150) {
        return false;
    };
};

#endif //CARGAME_COLLIDER_H