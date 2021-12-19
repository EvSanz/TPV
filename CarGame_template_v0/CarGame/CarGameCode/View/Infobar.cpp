#include "Infobar.h"
#include "../Logic/Game.h"

void Infobar::drawInfo() {
    int x = game->font->getSize() / 2;
    int y = game->font->getSize() / 2;

    SDL_Rect rect = { 0, 0, game->getWindowWidth(),
                     int(game->font->getSize() * 1.8) };
    Box(rect, BLACK).render(game->renderer);

    double distance = game->roadLength - game->car->getX();

    string s = "Pos: X:" + to_string(int(game->car->getX())) + " Y:"
        + to_string(int(game->car->getY())) + " Power:"
        + to_string(int(game->car->getPower())) + " Speed:"
        + to_string(int(game->car->getSpeed()));

    if (BadObject::instances > -1) {
        s += " Obstaculos:" + to_string(int(BadObject::instances));
    }

    if (distance > -1)
        s += " Distancia res:" + to_string(int(distance));

    s += " Coins:" + to_string(int(game->car->getCoins()));

    s += " Tiempo:" + to_string(int(SDL_GetTicks() - game->startTime));

    game->renderText(s, x, y);
}

void Infobar::drawHelp() {
    int x = game->font->getSize() / 2;
    int y = game->font->getSize() * 2;

    for (auto a : game->helpInfo) {
        game->renderText(a, x, y);
        y += game->font->getSize();
    }
}

void Infobar::drawState() {
    int x = game->font->getSize() / 2;
    int y = game->getWindowHeight() - game->font->getSize();

    string a = "State " + game->getStringFromEnum(game->state);
    game->renderText(a, x, y);
}