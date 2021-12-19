#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"
#include "GameObjects/GameObject.h"

class GameObjectGenerator {

    Point2D<int> static generateRandomPosition(Game* game, GameObject* o);

    void static addInRandomPosition(Game* game, GameObject* o, int x, int y, TextureName name);
    void static addInPosition(Game* game, GameObject* o, int w, int h, TextureName textureName);

protected:
    Game* game = nullptr;

public:
    static void generateRocks(Game *game, int N_ROCKS = 0, int N_LIVES = 0, int N_COINS = 0,
        int N_TURBO = 0, int N_SUPERROCK = 0, int N_OIL = 0, int  N_TRUCK = 0){

        for(int i = 0; i < N_ROCKS; i++)
            addInRandomPosition(game, new Obstacle(game), 50, 50, rockTexture);

        for (int i = 0; i < N_LIVES; i++)
            addInRandomPosition(game, new PowerUp(game), 40, 40, powerUpTexture);

        for (int i = 0; i < N_COINS; i++)
            addInRandomPosition(game, new Coin(game), 20, 20, coinTexture);

        for (int i = 0; i < N_TURBO; i++)
            addInRandomPosition(game, new Turbo(game), 80, 40, turboTexture);

        for (int i = 0; i < N_SUPERROCK; i++)
            addInRandomPosition(game, new SuperRock(game), 160, 80, superRockTexture);

        for (int i = 0; i < N_OIL; i++)
            addInRandomPosition(game, new oil(game), 40, 40, oilTexture);

        for (int i = 0; i < N_TRUCK; i++)
            addInRandomPosition(game, new Truck(game), 120, 60, truckTexture);
    } 

    static void generateBullet(Game* game)
    {
        addInPosition(game, new Bullet(game), 20, 5, bulletTexture);
    }
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
