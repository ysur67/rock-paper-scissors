#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include "controller.h"
#include <string>
using std::string;

class GameController;

class IScreen {
    public:
        static const char name = 'a';
        bool shouldUpdateDisplay = false;
        virtual void display() = 0;
        virtual void update() = 0;
        virtual ~IScreen() = default;
};

class BaseGameScreen : public IScreen {
    public:
        BaseGameScreen(GameController* controller);
        GameController* getController();

    protected:
        GameController* controller;
        void clearScreen();
        void displayUserChoiceError(char choice);
};

class MainMenu : public BaseGameScreen {
    public:
        static const char name = 'M';
        MainMenu(GameController* controller) : BaseGameScreen(controller) {};
        void display() override;
        void update() override;
    private:
        static const char START_GAME_ID = '1';
        static const char EXIT_GAME_ID = '2';
        void displayInfo();
};


class SelectFigureScreen : public BaseGameScreen {
    public:
        static const char name = 'F';
        SelectFigureScreen(GameController* contoller) : BaseGameScreen(contoller) {};
        void display() override;
        void update() override;

    protected:
        static const char ROCK_ID = '1';
        static const char PAPER_ID = '2';
        static const char SCISSORS_ID = '3';
};

#endif
