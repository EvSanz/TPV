#ifndef CARGAME_GAMEOBJECTCONTAINER_H
#define CARGAME_GAMEOBJECTCONTAINER_H

#include <vector>
#include "GameObjects/BadObject.h"

using namespace std;

class GameObject;
class Collider;

class GameObjectContainer { 
    //Este coge todos los objetos que no sean coche
    vector<GameObject*> gameObjects;

public:

    GameObject* getObject(int numObject) { return gameObjects[numObject]; }

    GameObjectContainer(){};

    ~GameObjectContainer() 
    {
        for (auto g : gameObjects) {
            g->onDelete();
            delete g;
        }
        gameObjects.clear();

    }

    int getVecSize() { return gameObjects.size(); }

    void update()
    {
        for (auto i : gameObjects)
        {
            if (i != nullptr)
                i-> update();
        }
    }

    void draw()
    {
        for (auto i : gameObjects)
        {
            if (i != nullptr)
                i-> draw();
        }
    }

    //void drawDebug();

    void add(GameObject* gameObject) 
    { 
        gameObjects.push_back(gameObject); 

        gameObject->onEnter();
    }

    void removeDead()
    {
        for (int i = 0; i < gameObjects.size(); i++)
        {
            if (gameObjects[i]->toDelete()) {
                removeObject(getObject(i), i);
            }
        }
    }

    void removeObject(GameObject* g, int i)
    {
        if (g != nullptr)
        {
            gameObjects.erase(gameObjects.begin() + i);
            g->onDelete();
            delete g;
            g = nullptr;
        }
    }

    bool hasCollision(GameObject* g) { return getCollisions(g).size() > 0; }

    vector<Collider*> getCollisions(GameObject* g)
    {
        vector<Collider*> collisions; 

        for (auto i : gameObjects)
        {
            if (i != nullptr &&
                SDL_HasIntersection(&i->getCollider(), &g->getCollider()))
            {
                collisions.push_back(i);
            }
        }

        return collisions; 
    }

    void wave() {
        for (auto i : gameObjects)
        {
            if (i != nullptr)
                i->wave();
        }
    }

};


#endif //CARGAME_GAMEOBJECTCONTAINER_H
