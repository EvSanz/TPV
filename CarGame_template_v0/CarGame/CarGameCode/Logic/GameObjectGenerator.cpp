#include "GameObjectGenerator.h"

Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* o)
{
    int x = 200 + rand() % (game->getRoadLeght() - 200);
    int y = (o->getHeight() / 2) + rand() %
        (game->getWindowHeight() - o->getHeight());

    o->setPosition(x, y);
    
    return Point2D<int>(x,y);
}

void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* o)
{ 
    generateRandomPosition(game, o);
    if (!game->con->hasCollision(o))
        game->con->add(o);
    else {
        delete o;
    }
}

void GameObjectGenerator::addInPosition(Game* game, GameObject* o)
{
    int x = game->car->getX() + game->car->getWidth() / 2;
    int y = game->car->getY(); 

    o->setPosition(x, y); 

    game->con->add(o); 
}

