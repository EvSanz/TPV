#pragma once

//Includes
#include "Command.h"

class MoveCommand : public Command {

    //Booleano de subida (Flecha arriba)
    bool bUp = false;
    //Booleano de bajada (Flecha abajo)
    bool bDown = false;

public:

    //Informacion que aparecera en el panel de ayuda
    const string INFO_STRING = "[UP/DOWN] to move";

    MoveCommand() {
        info_string = INFO_STRING;
    };
    ~MoveCommand() = default;
    bool parse(SDL_Event& event) override;
    void execute() override;
};