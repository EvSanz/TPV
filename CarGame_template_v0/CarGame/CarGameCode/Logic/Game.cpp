//
// Created by eys on 20/8/21.
//

#include "Game.h"
#include "GameObjectGenerator.h"

Game::Game(string name, int width, int height, int roadLength) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    doExit = false;
    font = new Font("../Images/Monospace.ttf", 12);
    infoBar = new Infobar(this);
}

void Game::changeState()
{
    if (state == Menu || state == GameOver)
    {
        if (state == GameOver)
            con->~GameObjectContainer();

        state = Playing;
        startGame(); 
    }

}

void Game::startGame() {

    finished = false;
    srand(time(NULL));

    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height / 2.0); 

    maxObs = 20;
    removed = 0;
    con = new GameObjectContainer();
    GameObjectGenerator::generateRocks(this, maxObs);
    GameObjectGenerator::generateLives(this, 5);

    maxObs -= removed;

    goal = new Goal(this);
    goal->setDimension(GOAL_WIDTH, getWindowHeight());
    goal->setPosition(roadLength, getWindowHeight()/2);
    startTime = SDL_GetTicks();
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
    if(car != nullptr)
        delete car;
    
    con->~GameObjectContainer();
    delete con;
    con = nullptr;

    if(goal != nullptr)
        delete goal;
    
    if(font != nullptr)
        delete font;

    if(textureContainer != nullptr)
        delete textureContainer;

    if (infoBar != nullptr)
        delete infoBar;
}

void Game::update(){

    car->update();

    con->removeDead();

    if (!car->isAlive()) {
        finished = true;
    }

    if (SDL_HasIntersection(&car->getCollider(),
        &goal->getCollider())) {
        endTime = SDL_GetTicks() - startTime;
        finished = true;
    }
}


void Game::draw(){

    car->draw(); 
    con->draw();
    goal->draw();
    drawInfo();
    //info->drawInfo();
}

void Game::drawInfo() {
    /*int x = font->getSize() / 2;
    int y = font->getSize() / 2;

    SDL_Rect rect = {0, 0, getWindowWidth(),
                     int(font->getSize() * 1.8)};
    Box(rect, BLACK).render(renderer);

    double distance = roadLength - car->getX();

    string s = "Pos: X:" + to_string(int(car->getX())) + " Y:"
        + to_string(int(car->getY())) + " Power:"
        + to_string(int(car->getPower())) + " Speed:"
        + to_string(int(car->getSpeed()));

    if (maxObs > -1) {
        s += " Obstaculos:" + to_string(int(BadObject::instances));
    }

    if (distance > -1)
        s += " Distancia res:" + to_string(int(distance));

    s += " Tiempo:" + to_string(int(SDL_GetTicks() - startTime));

    renderText(s, x, y);*/
    infoBar->drawInfo();
}

void Game::gameOver()
{
    int x = getWindowWidth() / 3;
    int y = getWindowHeight() / 3;
    
    if (car->isAlive())
    {
        string s = "Congratulations!";
        renderText(s, x, y);
        string t = "User wins";
        renderText(t, x, y + font->getSize());
        string u = "Time: " + to_string(endTime) + " ms";
        renderText(u, x, y + font->getSize() * 2);
        string v = "Press space to play again";
        renderText(v, x, y + font->getSize() * 3);
    }
    else {
        string s = "GAME OVER";
        renderText(s, x, y);
        string t = "User loses";
        renderText(t, x, y + font->getSize());
        string u = "Press space to retry";
        renderText(u, x, y + font->getSize() * 2);
    }
}

void Game::setUserExit() {
    doExit = true;
}

bool Game::isUserExit() {
    return doExit;
}

int Game::getWindowWidth(){
    return width;
}

int Game::getWindowHeight() {
    return height;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::setRenderer(SDL_Renderer *_renderer) {
    renderer = _renderer;
}

void Game::loadTextures() {
    if(renderer == nullptr)
        throw string("Renderer is null");

    textureContainer = new TextureContainer(renderer);
}

void Game::renderText(string text, int x, int y, SDL_Color color){
    font->render(renderer, text.c_str(), x, y, color);
}

bool Game::doQuit() {
    return isUserExit();
}

Texture *Game::getTexture(TextureName name) {
    return textureContainer->getTexture(name);
}

Point2D<int> Game::getOrigin() {
    return {int(-(car->getX() - car->getWidth())), 0};
}

/*void Game::carUse(string instruction) {
    if (instruction == "accl") {
        car->speedControl(true);
    }
    else if (instruction == "decl") {
        car->speedControl(false);
    }
    else if (instruction == "TurnL") {
        car->verticalmove(true);
    }
    else if (instruction == "TurnR") {
        car->verticalmove(false);
    }
}*/
void Game::carSpeedo(bool stade) {
  
    car->speedControl(stade);  
}

void Game::carUpDown(bool state) {
    car->verticalmove(state);
}

void Game::menu() {
    int x = getWindowWidth() / 3;
    int y = getWindowHeight() / 3;

    string s = "Welcome to Super Cars";
    renderText(s, x, y);
    string t = "Level: 0";
    renderText(t, x, y + font->getSize());
    string u = "Press space to start";
    renderText(u, x, y + font->getSize() * 2);

}

bool Game::isRebased(GameObject* gameObject) {
    if (gameObject != nullptr &&
        gameObject->getX() < car->getX() - car->getWidth() / 2)
    {
        return true;
    }
    else
        return false;
}