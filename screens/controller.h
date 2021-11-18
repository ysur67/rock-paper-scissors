#pragma once
#ifndef CONTROLLER_H
#define CONTOLLER_H
#include "screen.h"
#include <memory>
using std::auto_ptr;

class BaseGameScreen;

class GameController {
    private:
        BaseGameScreen* currentScreen;

    public:
        GameController();
        void update();
        void setScreen(BaseGameScreen *newScreen);
        void exitGame();
};

#endif
