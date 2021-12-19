#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"
#include "GameObjects/GameObject.h"

class GameObjectGenerator {

    Point2D<int> static generateRandomPosition(Game* game, GameObject* o);

    void static addInRandomPosition(Game* game, GameObject* o);
    void static addInPosition(Game* game, GameObject* o);

protected:
    Game* game = nullptr;

public:
    static void generateRocks(Game *game, int N_ROCKS = 0, int N_LIVES = 0, int N_COINS = 0,
        int N_TURBO = 0, int N_SUPERROCK = 0, int N_OIL = 0, int  N_TRUCK = 0){

        for(int i = 0; i < N_ROCKS; i++)
            addInRandomPosition(game, new Obstacle(game));

        for (int i = 0; i < N_LIVES; i++)
            addInRandomPosition(game, new PowerUp(game));

        for (int i = 0; i < N_COINS; i++)
            addInRandomPosition(game, new Coin(game));

        for (int i = 0; i < N_TURBO; i++)
            addInRandomPosition(game, new Turbo(game));

        for (int i = 0; i < N_SUPERROCK; i++)
            addInRandomPosition(game, new SuperRock(game));

        for (int i = 0; i < N_OIL; i++)
            addInRandomPosition(game, new oil(game));

        for (int i = 0; i < N_TRUCK; i++)
            addInRandomPosition(game, new Truck(game));
    } 

    static void generateBullet(Game* game)
    {
        addInPosition(game, new Bullet(game));
    }
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
