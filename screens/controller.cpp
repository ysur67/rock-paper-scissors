#include <iostream>
#include <string>
#include "controller.h"
using std::string;
using std::cout;


GameController::GameController() {
    MainMenu* screen = new MainMenu(this);
    this->currentScreen = screen;
    this->currentScreen->display();
};

void GameController::setScreen(BaseGameScreen *newScreen) {
    this->currentScreen = newScreen;
    this->currentScreen->display();
}

void GameController::update() {
    this->currentScreen->update();
    if (this->currentScreen->shouldUpdateDisplay) {
        this->currentScreen->display();
    }
}

void GameController::exitGame() {
    std::exit(1);
}
