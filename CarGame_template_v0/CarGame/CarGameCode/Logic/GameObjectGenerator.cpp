#include "GameObjectGenerator.h"

Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* o)
{
    int x = 200 + rand() % (game->getRoadLeght() - 200);
    int y = (o->getHeight() / 2) + rand() %
        (game->getWindowHeight() - o->getHeight());

    o->setPosition(x, y);
}

void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* o)
{
    o->setDimension(50, 50);
    generateRandomPosition(game, o);
    game->con->add(o);
}