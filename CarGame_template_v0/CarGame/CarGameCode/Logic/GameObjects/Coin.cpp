//Includes
#include "Coin.h"
#include "../Game.h"

bool Coin::receiveCarCollision(Car* car) {

    //Si recibe una colision con el coche, desaparece y a�ade
    //una moneda al contador de monedas 
    car->moreCoins();
    alive = false;
    return true;
}
