#ifndef CARGAME_GAMEOBJECTCONTAINER_H
#define CARGAME_GAMEOBJECTCONTAINER_H

//Includes
#include <vector>
#include "GameObjects/BadObject.h"

using namespace std;

//Clases
class GameObject;
class Collider;

class GameObjectContainer { 

    //Vector donde estaran todos los objetos menos el coche y la meta
    vector<GameObject*> gameObjects;

public:

    GameObject* getObject(int numObject) { return gameObjects[numObject]; }

    GameObjectContainer(){};

    ~GameObjectContainer() 
    {
        //Recorremos el vector de los objetos, eliminando uno a uno 
        for (auto g : gameObjects) {
            g->onDelete();
            delete g;
        }
        gameObjects.clear();
    }

    //Devolvemos el tamaño del vector de objetos 
    int getVecSize() { return gameObjects.size(); }

    void update()
    {
        //Recorremos el vector de los objetos, modificandolos si existen 
        for (auto i : gameObjects)
        {
            if (i != nullptr)
                i-> update();
        }
    }

    void draw()
    {
        //Recorremos el vector de los objetos, dibujandolos si existen 
        for (auto i : gameObjects)
        {
            if (i != nullptr)
                i-> draw();
        }
    }

    //Metodo para añadir objetos al vector 
    void add(GameObject* gameObject) 
    { 
        gameObjects.push_back(gameObject); 

        gameObject->onEnter();
    }

    //Metodo para eliminar del vector los objetos que ya no existan
    void removeDead()
    {
        for (int i = 0; i < gameObjects.size(); i++)
        {
            if (gameObjects[i]->toDelete()) {
                removeObject(getObject(i), i);
            }
        }
    }

    //Metodo para eliminar un objeto del vector si existe
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

    //Metodo para indicar si un objeto concreto ha colisionado con algo o no 
    bool hasCollision(GameObject* g) { return getCollisions(g).size() > 0; }

    //Vector que devuelve las colisiones que sufre un objeto concreto  
    vector<Collider*> getCollisions(GameObject* g)
    {
        //Vector de colisiones
        vector<Collider*> collisions; 

        //Recorremos el vector de los objetos 
        for (auto i : gameObjects)
        {
            //Si el objeto existe y ha colisionado con el objeto
            //fijo, añadimos dicha colision al vector de colisiones
            if (i != nullptr &&
                SDL_HasIntersection(&i->getCollider(), &g->getCollider()))
            {
                collisions.push_back(i);
            }
        }

        return collisions; 
    }

    //Vector que devuelve el vector de objetos 
    vector<GameObject*> getVector()
    {
        vector<GameObject*> objetos;

        for (auto i : gameObjects)
        {
            if (i != nullptr)
            {
                objetos.push_back(i);
            }
        }

        return objetos; 
    }
};


#endif //CARGAME_GAMEOBJECTCONTAINER_H
