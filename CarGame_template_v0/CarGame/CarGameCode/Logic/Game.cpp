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

    if (car != nullptr)
        delete car;
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height / 2.0);
    car->setTextureObject(carTexture);

    if (con != nullptr) {
        delete con;
        con = nullptr;
    }
    con = new GameObjectContainer();
    GameObjectGenerator::generateRocks(this, 5, 10, 10, 5, 3, 5, 6); 

    if (goal != nullptr)
        delete goal;
    goal = new Goal(this);
    goal->setDimension(GOAL_WIDTH, getWindowHeight());
    goal->setPosition(roadLength, getWindowHeight()/2);
    goal->setTextureObject(goalTexture); 
    startTime = SDL_GetTicks();
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
    if(car != nullptr)
        delete car;
    
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

    con->update(); 

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

vector<GameObject*> Game::getCollisions()
{
    return con->getVector(); 
}

void Game::draw(){
    //se dibuja el coche el ultimo para que cuando 
    //este pase por encima de los objetos se dibuje 
    //el coche encima de ellos 
    con->draw();
    goal->draw();
    car->draw();
    drawInfo();
}

void Game::drawInfo() {
    infoBar->drawInfo();
    if (help)
        drawHelp(); 
    drawStateName(); 
}

void Game::drawHelp()
{
    infoBar->drawHelp(); 
}

void Game::drawStateName()
{
    infoBar->drawState();
}

void Game::setState(enum state)
{

}

void Game::gameOver()
{
    int x = getWindowWidth() / 3;
    int y = getWindowHeight() / 3;
    int inc = font->getSize();

    if (car->isAlive())
    {
        string s[] = { "Congratulations!",
            "User wins",
            "Time: " + to_string(endTime) + " ms",
            "Press space to play again"
        };
        for (auto a : s) {
            renderText(a, x, y);
            y += inc;
        }
    }
    else {
        string s[] = { "GAME OVER",
            "User loses",
            "Press space to retry"
        };
        for (auto a : s) {
            renderText(a, x, y);
            y += inc;
        }
    }
    infoBar->drawState();
}

void Game::setUserExit() {
    doExit = true;
}

bool Game::spendMoney(int cost)
{
    if (car->getCoins() >= cost) {
        car->spentCoins(cost);
        return true;
    }

    else
        return false; 
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

void Game::renderVectorText(vector<string> text, int x, int y, SDL_Color color = {0,0,0 })
{
    int inc = font->getSize() * 1.5;

    for (auto s : text) {
        renderText(s, x, y, color);
        y += inc;
    }
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

void Game::carSpeedo(bool stade) {
    car->speedControl(stade);  
}

void Game::carUpDown(bool state) {
    car->verticalmove(state);
}

void Game::menu() {

    int x = getWindowWidth() / 3;
    int y = getWindowHeight() / 3;
    int inc = font->getSize();

    string s[] = { "Welcome to Super Cars",
        "Level: 0",
        "Press space to start",
        "Press [h] to toggle help"
    };

    for (auto a : s) {
        renderText(a, x, y);
        y += inc;
    }
    infoBar->drawState();
}

bool Game::isRebased(GameObject* gameObject) {
    return gameObject != nullptr &&
        (gameObject->getX() < car->getX() - car->getWidth() / 2
            || gameObject->getX() >= goal->getX() - goal->getWidth() / 2);
}