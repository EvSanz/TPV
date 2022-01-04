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

#include "GameObjects/objects.h"

#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"

#include "GameObjects/BadObject.h"
#include "GameObjects/GoodObject.h"
#include "../View/Infobar.h"

using namespace std;

class Game{

private:

    string name;
    bool doExit;

    int width, height;
    int roadLength;
    Goal* goal = nullptr;
    int startTime = 0;
    int endTime = 0; 
    int time = 0; 

    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;

    Infobar* infoBar;
    vector<string> helpInfo;
    bool help = false;

public:

    GameObjectContainer* con = nullptr;
    Car* car = nullptr;

    friend class Infobar;
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;
    const unsigned  int GOAL_WIDTH = 50;


    bool finished;
    enum { Menu, Playing, GameOver } state;
    string getStringFromEnum(int e){ //esto es para que devuelva el estado en el que esta en el metodo de Infobar
        switch (e) {
        case 0: return "Menu";
        case 1: return "Playing";
        case 2: return "GameOver";
        default: return "Bad MyEnum";
        }
    }

    Game(string name, int width, int height, int roadLength);
    ~Game();

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
    void renderVectorText(vector<string> text, int x, int y, SDL_Color color = {0,0,0});

    void drawInfo();
    void drawHelp();
    void drawStateName(); 
    void setState(enum state);

    void setElapsedTime(int totalTime) { time = totalTime; }
    bool gameFinished() { return finished; }

    bool spendMoney(int cost);
    void carSpeedo(bool stade);
    void carUpDown(bool state);

    vector<GameObject*> getCollisions();

    void gameOver();

    void menu();

    void appendHelpInfo(string info_string) { helpInfo.push_back(info_string); };

    bool isRebased(GameObject* gameObject);

    void changeState(); 
    
    void toggleHelp() { help = !help; }
};


#endif //CARGAME_GAME_H
