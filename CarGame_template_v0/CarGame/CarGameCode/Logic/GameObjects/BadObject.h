#ifndef CARGAME_BADOBJECT_H
#define CARGAME_BADOBJECT_H

//Includes
#include "GameObject.h"

//Clases extras
class Game;

class BadObject : public GameObject {

protected:

    //Booleano de estado actual 
    bool alive;

public:

    //Contador de BadObjects
    static int instances;

    BadObject(Game *game): GameObject(game) {
        alive = true;
    };
    ~BadObject() override = default;

    void update() override{};
    bool toDelete() override;

    void onEnter() override;
    void onDelete() override;
    void static reset();
    bool wave(int value = 150) override;
};


#endif //CARGAME_BADOBJECT_H
