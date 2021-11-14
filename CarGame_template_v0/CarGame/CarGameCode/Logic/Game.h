//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H

#include <iostream>
#include <string>
#include <vector>

#include "../View/TextureContainer.h"
#include "../View/Texture.h"
#include "../View/Box.h"
#include "../View/Font.h"

#include "GameObjects/Car.h"
#include "GameObjects/Obstacles.h"
#include "GameObjects/Goal.h"
#include "GameObjects/PowerUp.h"

#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"


using namespace std;

class Game{

private:

    string name;
    bool doExit;

    int width, height;
    int maxObs = 20;
    int removed = 0;
    Car *car = nullptr;
    int roadLength;
    Goal* goal = nullptr;
    //array<Obstacle*, 20> obs;
    int startTime = 0;
    int endTime = 0; 

    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;

public:

    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;
    const unsigned  int GOAL_WIDTH = 50;


    bool finished;
    //enum { Menu, Playing, GameOver } state;

    Game(string name, int width, int height, int roadLength);
    ~Game();


    //GameObjectGenerator *gen;
    GameObjectContainer *con;

    void startGame();
    void update();
    void draw();

    void setUserExit();
    bool isUserExit();
    bool doQuit();

    int getWindowWidth();
    int getWindowHeight();
    int getRoadLeght() { return roadLength; }

    Point2D<int> getOrigin();

    string getGameName();

    void setRenderer(SDL_Renderer *renderer);
    void loadTextures();
    Texture *getTexture(TextureName name);
    SDL_Renderer *getRenderer();
    void renderText(string text, int x, int y, SDL_Color color={0,0,0});

    void drawInfo();

    void carUse(string instruction);

    void gameOver();

    void menu();

    void appendHelpInfo(string info_string);

    bool isRebased(GameObject* gameObject);

    void increaseRemoved() { removed++; }
};


#endif //CARGAME_GAME_H
