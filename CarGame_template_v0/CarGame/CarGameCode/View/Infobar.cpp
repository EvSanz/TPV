//Include
#include "Infobar.h"
#include "../Logic/Game.h"

//Metodo para renderizar la informacion del juego 
void Infobar::drawInfo() {

    int x = game->font->getSize() / 2;
    int y = game->font->getSize() / 2;

    //Creamos la zona donde estara el texto del juego 
    SDL_Rect rect = { 0, 0, game->getWindowWidth(),
                     int(game->font->getSize() * 1.8) };
    Box(rect, BLACK).render(game->renderer);

    //Distancia que queda para alcanzar la linea de meta 
    double distance = game->getRoadLeght() - game->car->getX();

    //Linea de texto donde escribimos las coordenadas, vidas, 
    //monedas, tiempo y velocidad del coche
    string s = "Pos: X:" + to_string(int(game->car->getX())) + " Y:"
        + to_string(int(game->car->getY())) + " Power:"
        + to_string(int(game->car->getPower())) + " Speed:"
        + to_string(int(game->car->getSpeed())) + " Coins:" 
        + to_string(int(game->car->getCoins())) + " Tiempo:" 
        + to_string(int(SDL_GetTicks() - game->startTime));

    //Si hay obstaculos, añadimos el numero a la linea de texto 
    if (BadObject::instances > -1) {
        s += " Obstaculos:" + to_string(int(BadObject::instances));
    }

    //Si hemos recorrido distancia, añadimos la que nos queda al texto 
    if (distance > -1)
        s += " Distancia res:" + to_string(int(distance));

    game->renderText(s, x, y);
}

//Metodo para renderizar el panel de texto 
void Infobar::drawHelp() {

    //Establecemos sus coordenadas de posicion del panel
    int x = game->font->getSize() / 2;
    int y = game->font->getSize() * 2;

    //Hacemos un recorrido para escribir cada linea de texto
    for (auto a : game->helpInfo) {
        game->renderText(a, x, y);
        y += game->font->getSize();
    }
}

//Metodo para dibujar el nombre del estado actual del juego 
void Infobar::drawState() {

    //Establecemos sus coordenadas de posicion del panel
    int x = game->font->getSize() / 2;
    int y = game->getWindowHeight() - game->font->getSize();

    string a = "State " + game->getStringFromEnum(game->state);
    game->renderText(a, x, y);
}