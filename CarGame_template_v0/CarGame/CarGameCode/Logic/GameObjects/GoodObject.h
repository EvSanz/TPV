#ifndef CARGAME_GOODOBJECT_H
#define CARGAME_GOODOBJECT_H

//Include
#include "GameObject.h"

class GoodObject : public GameObject
{
protected:

    //Booleano de estado actual 
    bool alive;

public:

    //Contador de GoodObjects
    static int instances;

    GoodObject(Game* game) : GameObject(game) {
        alive = true;
    };
    ~GoodObject() override = default;

    void update() override {};
    bool toDelete() override;

    void onEnter() override;
    void onDelete() override;
    void static reset();
    bool wave(int value = 150) override;
};

#endif //CARGAME_GOODOBJECT_H
