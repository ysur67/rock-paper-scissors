#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include "controller.h"
#include <string>
#include "../figure.h"
using std::string;

class GameController;

class IScreen {
    public:
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
        SelectFigureScreen(GameController* contoller) : BaseGameScreen(contoller) {};
        void display() override;
        void update() override;
        static inline IFigure* getFigure(char code);

    protected:
        static const char ROCK_ID = '1';
        static const char PAPER_ID = '2';
        static const char SCISSORS_ID = '3';
};


class ComparingFiguresScreen : public BaseGameScreen {
    public:
        ComparingFiguresScreen(GameController* controller, IFigure* userFigure);
        void display() override;
        void update() override;
    private:
        IFigure* userFigure;
        IFigure* computerFigure;
        static const char TRY_AGAIN_ID = '1';
        static const char EXIT_ID = '2';
        static IFigure* getRandomFigure();
};

#endif
