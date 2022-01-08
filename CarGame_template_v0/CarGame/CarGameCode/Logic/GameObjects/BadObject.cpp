//Includes
#include "BadObject.h"
#include "../Game.h"

//Metodo para añadir uno al contador de objetos
void  BadObject::onEnter(){
    instances += 1;
};

//Metodo para restar uno al contador de objetos
void  BadObject::onDelete(){
    instances -= 1;
};

//Metodo para resetear el contador
void BadObject::reset(){
    instances = 0;
};

//Metodo para comprobar si debe ser eliminado un objeto o no 
bool BadObject::toDelete() {
    return !alive || game->isRebased(this); 
}

//Contador de BadObjects
int BadObject::instances = 0;

//Metodo para alejar todos los BadObjects unos pixeles
//cuando se activa la ola
bool BadObject::wave(int value) {
    setPosition(getX() + value, getY());
    return true;
}