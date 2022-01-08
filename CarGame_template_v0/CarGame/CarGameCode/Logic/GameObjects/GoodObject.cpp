//Includes
#include "GoodObject.h"
#include "../Game.h"

//Metodo para añadir uno al contador de objetos
void GoodObject::onEnter() {
    instances += 1;
};

//Metodo para restar uno al contador de objetos
void GoodObject::onDelete() {
    instances -= 1;
};

//Metodo para resetear el contador
void GoodObject::reset() {
    instances = 0;
};

//Metodo para comprobar si debe ser eliminado un objeto o no 
bool GoodObject::toDelete() {
    return !alive || game->isRebased(this);
}

//Contador de GoodObjects
int GoodObject::instances = 0;

//Metodo para acercar todos los GoodObjects unos pixeles
//cuando se activa la ola
bool GoodObject::wave(int value) {
    setPosition(getX() - value, getY());
    return true;
}