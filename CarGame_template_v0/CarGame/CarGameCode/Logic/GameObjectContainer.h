#ifndef CARGAME_GAMEOBJECTCONTAINER_H
#define CARGAME_GAMEOBJECTCONTAINER_H

#include <vector>
using namespace std;

class GameObject;
class Collider;

class GameObjectContainer { //Este coge todos los objetos que no sean coche
    vector<GameObject*> gameObjects;
public:

    GameObjectContainer(){};
    ~GameObjectContainer();
    void update();
    void draw();
    void drawDebug();
    void add(GameObject *gameObject);
    void removeDead();
    bool hasCollision(GameObject *g);
    vector<Collider *> getCollisions(GameObject *g);
};


#endif //CARGAME_GAMEOBJECTCONTAINER_H
