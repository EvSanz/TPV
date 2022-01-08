#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H

//Includes
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

//Clases
class Game;

class Car : public GameObject {

private:

    //Valores fijos de aceleracion, freno, velocidad, vidas y monedas
    const double ACCELERATION = 1.3;
    const double DECELERATION = 0.9;
    const int VSPEED = 5;
    const int MAX_SPEED = 10;
    const int INITIAL_POWER = 3; 
    const int INITIAL_COINS = 3;

    //Valores modificables de velocidad, vidas y monedas
    double HSPEED = 1;
    int power = INITIAL_POWER;
    int coins = INITIAL_COINS;

    //Booleano para detectar si esta activado el turbo y contador del turbo
    bool isSpeed = false;
    int turboCounter;

public:

    Car(Game* game) : GameObject(game) { };
    ~Car() {};

    void update();
    
    //Metodos para devolver el valor de vidas, velocidad o monedas
    int getPower() { return power; };
    int getSpeed() { return HSPEED; };
    int getCoins() { return coins; }

    //Metodo para comprobar si el jugador tiene vidas
    bool isAlive() { return power > 0; }

    //Metodo para sumar uno a las vidas o monedas
    int moreLives() { return power++; }
    int moreCoins() { return coins++; }


    void speedControl(bool accelerate);
    void verticalmove(bool lTurn);
    void spentCoins(int price);
    void powerRemaining(int lessVidas);
    void resetValor();
    void moreSpeed();
    void lessSpeed(double retardo);
};


#endif //CARGAME_CAR_H
