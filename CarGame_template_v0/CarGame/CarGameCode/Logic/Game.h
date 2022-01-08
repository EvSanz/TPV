#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H

//Includes
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

class Game {

private:

    //Nombre del juego 
    string name;
    //Indica si el jugador ha salido del juego o no 
    bool doExit;
    //Ancho, altura
    int width, height;
    //Longitud del juego 
    int roadLength;
    //Tiempos para el cronometro
    int startTime = 0;
    int endTime = 0; 

    //Fuente de texto
    Font *font;
    //Barra de informacion
    Infobar* infoBar;
    //Contenedor de texturas
    TextureContainer* textureContainer;
    //Meta
    Goal* goal = nullptr;
    SDL_Renderer* renderer = nullptr;

    //Vector de informacion 
    vector<string> helpInfo;
    //Indica si se ve el texto de ayuda o no 
    bool help = false;

public:

    //Contenedor de objetos vacio
    GameObjectContainer* con = nullptr;
    //Coche
    Car* car = nullptr;

    friend class Infobar;

    //Ancho fijo del coche y meta, ademas del alto del coche
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;
    const unsigned  int GOAL_WIDTH = 50;

    //Indica si se ha terminado el juego 
    bool finished;

    //Estados del juego 
    enum { Menu, Playing, GameOver } state;

    //Devuelve el estado en el que esta el juego 
    string getStringFromEnum(int e){ 
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
    bool doQuit();

    int getWindowWidth();
    int getWindowHeight();

    //Metodo para devolver el tamaño de la carretera
    int getRoadLeght() { return roadLength; }

    Point2D<int> getOrigin();

    string getGameName();

    void setRenderer(SDL_Renderer *renderer);
    void loadTextures();
    Texture *getTexture(TextureName name);
    SDL_Renderer *getRenderer();
    void renderText(string text, int x, int y, SDL_Color color={0,0,0});
    void renderVectorText(vector<string> text, int x, int y, SDL_Color color = { 0,0,0 });

    void drawInfo();

    bool spendMoney(int cost);
    void carSpeedo(bool stade);
    void carUpDown(bool state);

    vector<GameObject*> getCollisions();

    void gameOver();

    void menu();

    void appendHelpInfo(string info_string) { helpInfo.push_back(info_string); };

    bool isRebased(GameObject* gameObject);

    void changeState(); 
    
    //Metodo para activar o desactivar el panel de ayuda
    void toggleHelp() { help = !help; }
};


#endif //CARGAME_GAME_H
