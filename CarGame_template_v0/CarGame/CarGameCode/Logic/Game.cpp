//
// Created by eys on 20/8/21.
//

#include "Game.h"

Game::Game(string name, int width, int height, int roadLength) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    doExit = false;
    font = new Font("../Images/Monospace.ttf", 12);
}


void Game::startGame() {
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height / 2.0); 

    for (int i = 0; i < maxObs; i++)
    {
        obs[i] = new Obstacle(this);
        obs[i]->setDimension(OBS_WIDTH, OBS_HEIGHT);
        obs[i]->setPosition(rand() % roadLength,
            rand() % getWindowHeight());
    }

    goal = new Goal(this);
    goal->setDimension(GOAL_WIDTH, getWindowHeight());
    goal->setPosition(roadLength, getWindowHeight()/2);
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
    delete car;

    for (int i = 0; i < maxObs; i++) 
        delete obs[i];

    delete goal;
    delete font;
    delete textureContainer;
}

void Game::update(){
    car->update();

    for (int i = 0; i < maxObs; i++)
    {
        if (obs[i] != nullptr &&
            obs[i]->getX() < car->getX() - car->getWidth() / 2)
            obs[i] = nullptr;

        if (obs[i] != nullptr &&
            SDL_HasIntersection(&car->getCollider(),
                &obs[i]->getCollider()))
        {
            obs[i] = nullptr;
            car->powerRemaining();
        }
    }
}


void Game::draw(){
    car->draw();
    goal->draw();

    for (int i = 0; i < maxObs; i++)
        obs[i]->draw();
        
    drawInfo();
}

void Game::drawInfo() {
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;

    SDL_Rect rect = {0, 0, getWindowWidth(),
                     int(font->getSize() * 1.8)};
    Box(rect, BLACK).render(renderer);

    string s = "Pos: X:" + to_string(int(car->getX())) + " Y:"
               + to_string(int(car->getY())) + " Power:"
               + to_string(int(car->getPower()));
    renderText(s, x, y);
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

void Game::carUse(string instruction) {
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
}
