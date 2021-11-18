#include <iostream>
#include <string>
#include "controller.h"
using std::string;
using std::cout;

GameController::GameController() {
    MainMenu screen = MainMenu(this);
    this->currentScreen = &screen;
};

void GameController::update() {
    (*this).currentScreen->update();
    if (this->currentScreen->shouldUpdateDisplay) {
        this->currentScreen->display();
    }
}

void GameController::setScreen(IScreen* newScreen) {
    this->currentScreen = newScreen;
    this->currentScreen->display();
}

void GameController::exitGame() {
    std::exit(1);
}
