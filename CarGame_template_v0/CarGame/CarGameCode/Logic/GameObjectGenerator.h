#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"
#include "GameObjects/GameObject.h"

class GameObjectGenerator {

    Point2D<int> static generateRandomPosition(Game* game, GameObject* o);

    void static addInRandomPosition(Game* game, GameObject* o, int x, int y);
    void static addInPosition(Game* game, GameObject* o);

protected:
    Game* game = nullptr;

public:
    static void generateRocks(Game *game, int N_ROCKS = 0, int N_LIVES = 0, int N_COINS = 0,
        int N_TURBO = 0, int N_SUPERROCK = 0){

        for(int i = 0; i < N_ROCKS; i++)
            addInRandomPosition(game, new Obstacle(game), 50, 50);

        for (int i = 0; i < N_LIVES; i++)
            addInRandomPosition(game, new PowerUp(game), 40, 40);

        for (int i = 0; i < N_COINS; i++)
            addInRandomPosition(game, new Coin(game), 20, 20);

        for (int i = 0; i < N_TURBO; i++)
            addInRandomPosition(game, new Turbo(game), 80, 40);

        for (int i = 0; i < N_SUPERROCK; i++)
            addInRandomPosition(game, new SuperRock(game), 160, 80);
    } 

    static void generateBullet(Game* game)
    {
        addInPosition(game, new Bullet(game));
    }
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
