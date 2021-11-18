#include <iostream>
#include <string>
#include "screen.h"
using std::string;
using std::cout;

BaseGameScreen::BaseGameScreen(GameController* controller) {
    this->controller = controller;
};

void BaseGameScreen::displayUserChoiceError(char choice) {
    this->clearScreen();
    cout << "ERROR" << std::endl;
    cout << "Your choice " << choice;
    cout << " does not match any selection of menu" << std::endl;
}

void BaseGameScreen::clearScreen() {
    std::system("clear");
}
