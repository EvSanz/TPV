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
    BadObject* badObject; 

public:

    GameObject* getObject(int numObject) { return gameObjects[numObject]; }

    GameObjectContainer(){};

    ~GameObjectContainer() 
    { 
        for (int i = 0; i < gameObjects.size(); i++)
        {
            if (!gameObjects[i]->isGood());
                //badObject->onDelete();
            removeObject(getObject(i), i);
        }

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

        if (!gameObject->isGood());
            //badObject->onEnter(); 
    }

    void removeDead()
    {
        for (auto i : gameObjects)
        {
            if (i == nullptr)
                delete i; 
        }
    }

    void removeObject(GameObject* g, int i)
    {
        if (g != nullptr)
        {
            gameObjects.erase(gameObjects.begin() + i);
            if (!g->isGood());
                //badObject->onDelete();
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
                //i = nullptr;
                collisions.push_back(i);
            }
        }

        return collisions; 
    }
};


#endif //CARGAME_GAMEOBJECTCONTAINER_H
