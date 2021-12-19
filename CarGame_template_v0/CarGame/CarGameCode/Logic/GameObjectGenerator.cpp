#include "GameObjectGenerator.h"

Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* o)
{
    int x = 200 + rand() % (game->getRoadLeght() - 200);
    int y = (o->getHeight() / 2) + rand() %
        (game->getWindowHeight() - o->getHeight());

    o->setPosition(x, y);
    
    return Point2D<int>(x,y);
}

void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* o, int x, int y, TextureName name)
{
    o->setDimension(x, y);
    o->setTextureObject(name); 
    generateRandomPosition(game, o);
    if (!game->con->hasCollision(o))
        game->con->add(o);
    else {
        game->increaseRemoved();
        delete o;
    }
}

void GameObjectGenerator::addInPosition(Game* game, GameObject* o, int w, int h, TextureName name)
{
    int x = game->car->getX() + game->car->getWidth() / 2;
    int y = game->car->getY(); 

    o->setPosition(x, y); 
    o->setDimension(w, h);
    o->setTextureObject(name);

    game->con->add(o); 
}

