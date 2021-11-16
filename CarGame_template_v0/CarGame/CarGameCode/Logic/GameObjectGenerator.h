#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"
#include "GameObjects/GameObject.h"

class GameObjectGenerator {

    Point2D<int> static generateRandomPosition(Game* game, GameObject* o);

    void static addInRandomPosition(Game* game, GameObject* o);

protected:
    Game* game = nullptr;

public:
    static void generateRocks(Game *game, int N_ROCKS = 0, int N_LIVES = 0, int N_COINS = 0){

        for(int i = 0; i < N_ROCKS; i++)
            addInRandomPosition(game, new Obstacle(game));

        for (int i = 0; i < N_LIVES; i++)
            addInRandomPosition(game, new PowerUp(game));

        for (int i = 0; i < N_COINS; i++)
            addInRandomPosition(game, new Coin(game));
    }   

    static void generateLives(Game* game, int N_LIVES = 0) {

        for (int i = 0; i < N_LIVES; i++)
            addInRandomPosition(game, new PowerUp(game));
    }

    static void generateCoins(Game* game, int N_COINS = 0) {

        for (int i = 0; i < N_COINS; i++)
            addInRandomPosition(game, new Coin(game));
    }
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
