//Includes
#include "GameObjectGenerator.h"

//Metodo para devolver las coordenadas aleatorias de un objeto 
Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* o)
{
    //Calculamos las coordenadas x e y de forma aleatoria, teniendo 
    //en cuenta el tamaño del juego 
    int x = 200 + rand() % (game->getRoadLeght() - 200);
    int y = (o->getHeight() / 2) + rand() %
        (game->getWindowHeight() - o->getHeight());

    o->setPosition(x, y);
    
    return Point2D<int>(x,y);
}

//Metodo para añadir un objeto en coordenadas aleatorias
void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* o)
{ 
    generateRandomPosition(game, o);

    //Si el objeto no sufre colisiones, lo añadimos. Si colisiona, lo eliminamos
    if (!game->con->hasCollision(o))
        game->con->add(o);
    else
        delete o;
}

//Metodo para añadir un objeto en coordenadas fijas 
void GameObjectGenerator::addInPosition(Game* game, GameObject* o)
{
    int x = game->car->getX() + game->car->getWidth() / 2;
    int y = game->car->getY(); 

    o->setPosition(x, y); 

    game->con->add(o); 
}

