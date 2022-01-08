//Includes
#include "Truck.h"

void Truck::update() {

    //Modificamos la posicion para que este en movimiento 
    //en direccion contraria al jugador
    setPosition(getX() - 0.5, getY());
}

