//Includes
#include "Car.h"
#include "../Game.h"

void Car::update() {

    //Cambiamos la posicion del objeto  
    setPosition(getX() + HSPEED, getY());
    
    //Creamos un vector donde guardamos las colisiones que 
    //se han detectado
    vector<Collider*> collisions = game->con->getCollisions(this);

    //Comprobamos todas las colisiones que han sucedido, y si han 
    //sido contra el coche
    for (auto c : collisions) {
        c->receiveCarCollision(this);
    }
    
    //Si esta siendo afectado por el turbo...
    if (isSpeed) {

        //Y el contador de turbo es superior al maximo
        if (turboCounter >= 150) {

            //Desactivamos el turbo y reseteamos la velocidad 
            isSpeed = false;
            HSPEED = 10;
        }

        else {

            //Si no supera el maximo, aumentamos el contador de turbo
            turboCounter++;
        }
    }
}

//Metodo para controlar la velocidad del coche
void Car::speedControl(bool accelerate) {
    
    //Si el jugador no ha perdido todas sus vidas...
    if (isAlive())
    {
        //Y esta acelerando...
        if (accelerate) {

            //La velocidad se multiplicara por la aceleracion
            HSPEED = HSPEED * ACCELERATION;

            //Y en el caso de superar el maximo, se 
            //dejara en el maximo permitido
            if (HSPEED > 10) {
                HSPEED = 10;
            }
        }

        //Si no esta acelerando, entonces la velocidad disminuira
        else {
            HSPEED = HSPEED * DECELERATION;
        }
    }

    //Si el jugador ha muerto, la velocidad sera nula 
    else
        HSPEED = 0;
}

//Metodo para controlar la posicion del coche
void Car::verticalmove(bool lTurn) {
    
    
    if (isAlive())
    {
        //Si el coche tiene velocidad...
        if (HSPEED >= 1) {

            //Dependiendo del valor del booleano, subira o bajara 
            //teniendo en cuenta que no puede superar los limites de la pantalla
            if (lTurn) {
                setPosition(getX(), getY() - VSPEED);
                if (getY() < getHeight() / 2)
                    setPosition(getX(), getHeight() / 2);
            }
            else {
                setPosition(getX(), getY() + VSPEED);
                if (getY() > game->getWindowHeight() - getHeight() / 2)
                    setPosition(getX(), game->getWindowHeight() - getHeight() / 2);
            }
        }
    }

    else
        //Si no esta vivo, la posicion sera fija 
        setPosition(getX(), getY());
}

//Metodo para restar vidas 
void Car::powerRemaining(int lessVidas)
{
    if (isAlive())
    {
        //Cuando recibe un impacto, perdemos vidas y reduce la velocidad 
        HSPEED = 0.1; 
        power = power - lessVidas;
    }
}

//Metodo para resetear los valores del coche
void Car::resetValor()
{
    //Establecemos la velocidad del coche a 1, restauramos las 
    //vidas y posicionamos el coche en el centro de un lateral
    HSPEED = 1;
    power = INITIAL_POWER;
    setPosition(getWidth(), game->getWindowHeight() / 2.0); 
}

//Metodo para gastar monedas dependiendo del coste
void Car::spentCoins(int price)
{
    coins = coins - price;
}

//Metodo para ralentizar el coche
void Car::lessSpeed(double retardo)
{
    //Si la velocidad del coche no es nula
    if (HSPEED > 0)
    {
        //Disminuimos la velocidad multiplicandola por el retardo
        HSPEED = HSPEED * retardo; 

        //Pero nos aseguramos de que siga habiendo velocidad
        if (HSPEED <= 1)
            HSPEED = 1; 
    }

    //En el caso de que sea nula, hacemos que se mueva con lentitud
    else
        HSPEED = 1;
}

//Metodo para acelerar al entrar en un turbo
void Car::moreSpeed() 
{
    //Establecemos la velocidad a 20, activamos el bool del 
    //turbo y reseteamos el contador de este
    HSPEED = 20;
    isSpeed = true;
    turboCounter = 0;
}