//
// Created by eys on 20/8/21.
//

#include "ViewController.h"
#include "Command/QuitCommand.h"


ViewController::ViewController(Game *_game) {
    game = _game;
    cout << "[DEBUG] frame duration: " << frameDuration() << " ms" << endl;
    initSDL();

    game->setRenderer(renderer);
    game->loadTextures();

    commandFactory = new CommandFactory(game); 
    commandFactory -> add(new MoveCommand());
    commandFactory -> add(new AccCommand());
    //commandFactory -> add(new DebugCommand());
    commandFactory -> add(new HelpCommand());
    commandFactory -> add(new QuitCommand());
    game -> startGame();
}

void ViewController::run() {
    uint32_t startTime = 0;
    uint32_t frameTime;
    state = Menu;
    startGame = false;
   

    while(!game->doQuit()){
        frameTime = SDL_GetTicks() - startTime;
        handleEvents();
        if (frameTime >= frameDuration()) {
            switch (state) {
            case Menu:
                clearBackground();
                game->menu();
                SDL_RenderPresent(renderer);
                break;
            case Playing:
                clearBackground();
                game->update();
                game->draw();
                SDL_RenderPresent(renderer);
                if (game->finished) {
                    state = GameOver;
                    startGame = false;
                }
                break;
            case GameOver:
                clearBackground();
                game->gameOver();
                SDL_RenderPresent(renderer);
                break;
            default:
                break;
            }
            
            startTime = SDL_GetTicks();
        }
        else{
            SDL_Delay(frameDuration() - frameTime);
        }
    }
}

void ViewController::clearBackground() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void ViewController::handleEvents() {
    //SDL_Event event;
    //while (SDL_PollEvent(&event) ){
    //    if( event.type == SDL_QUIT)
    //        game->setUserExit();
    //    if (event.type == SDL_KEYDOWN) {
    //        //SDL_Keycode key = event.key.keysym.sym;
    //        switch (event.key.keysym.sym) {
    //        case SDLK_LEFT:
    //            if(startGame)
    //                game->carUse("decl");
    //            break;
    //        case SDLK_RIGHT:
    //            if(startGame)
    //                game->carUse("accl");
    //            break;
    //        case SDLK_UP:
    //            if(startGame)
    //                game->carUse("TurnL");
    //            break;
    //        case SDLK_DOWN:
    //            if(startGame)
    //                game->carUse("TurnR");
    //            break;
    //        case SDLK_ESCAPE:
    //            game->setUserExit();
    //            break;
    //        case SDLK_SPACE:
    //            if (!startGame) {
    //                startGame = true;
    //                state = Playing;
    //                game->startGame();
    //            }
    //            break;
    //        default:
    //            break;
    //        }
    //    }

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        Command* command = commandFactory-> getCommand(event);
        if (command != nullptr) {
            command->execute(); 
            break;
        }
    }
}

uint32_t ViewController::frameDuration() {
    return 1000 / FRAME_RATE;
}

void ViewController::initSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(game->getGameName().c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              game->getWindowWidth(),
                              game->getWindowHeight(),
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (window == nullptr || renderer == nullptr)
        throw string("Error creating SDL window or renderer");

    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, &screenSurface->clip_rect, 0xFF);
    SDL_UpdateWindowSurface(window);
}

ViewController::~ViewController() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
