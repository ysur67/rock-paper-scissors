#include <string>
#include <iostream>
#include "screen.h"
using std::string;
using std::cout;
using std::cin;


void MainMenu::display() {
   displayInfo();
}

void MainMenu::displayInfo() {
    cout << std::endl << "ROCK-PAPER-SCISSORS" << std::endl;
    cout << std::endl << "Main Menu" << std::endl;
    cout << this->START_GAME_ID << ". Start new game" << std::endl;
    cout << this->EXIT_GAME_ID << ". Exit" << std::endl;
}

void MainMenu::update() {
    char userChoice;
    cin >> userChoice;
    if (userChoice != this->START_GAME_ID && userChoice != this->EXIT_GAME_ID) {
        return this->displayUserChoiceError(userChoice);
    }
    switch (userChoice) {
        case this->START_GAME_ID: {
            SelectFigureScreen* screen = new SelectFigureScreen(controller);
            this->controller->setScreen(screen);
            break;
        }
        case this->EXIT_GAME_ID:
            this->controller->exitGame();
            break;
        default:
            this->displayUserChoiceError(userChoice);
            break;
    }
}
