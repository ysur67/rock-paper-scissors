#pragma once
#ifndef CONTROLLER_H
#define CONTOLLER_H
#include "screen.h"

class IScreen;

class GameController {
    private:
        IScreen* currentScreen;

    public:
        GameController();
        void update();
        void setScreen(IScreen* newScreen);
        void exitGame();
};

#endif
