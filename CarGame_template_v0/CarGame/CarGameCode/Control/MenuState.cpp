#include "MenuState.h"

MenuState::MenuState(Game*game) : State(game)
{
	registerCommands(); 
}

void MenuState::registerCommands() {

	game -> clearHelp();
	commandFactory -> add(new HelpCommand());
	commandFactory -> add(new NextCommand());
	commandFactory -> add(new QuitCommand());
}

void MenuState::draw() {
	vector<string> texts = {
	"Welcome to Super Cars",
	"Press space to start",
	"Press [h] for help"
	};

	game->renderVectorText (texts, game->getWindowWidth() / 2 - 100,
		game->getWindowHeight()/2 - 50);
	game->drawHelp();
	game->drawStateName();
}
void MenuState::next() {
	game->setState(new PlayingState(game));
	delete this;
}

