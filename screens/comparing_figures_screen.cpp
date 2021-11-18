#include <string>
#include <iostream>
#include "screen.h"
#include "../figure.h"
#include <random>
#include <iostream>
using std::cout;
using std::string;
using std::cin;


ComparingFiguresScreen::ComparingFiguresScreen(GameController* controller, IFigure* userFigure) : BaseGameScreen(controller) {
    this->userFigure = userFigure;
    this->computerFigure = ComparingFiguresScreen::getRandomFigure();
};

IFigure* ComparingFiguresScreen::getRandomFigure() {
    std::random_device rd;   
    std::mt19937 rng(rd());    
    std::uniform_int_distribution<int> uni(1, 3); 
    auto randomInt = uni(rng);
    switch (randomInt) {
        case 1: {
            return new Rock();
        }
        case 2: {
            return new Paper();
        }
        case 3: {
            return new Scissors();
        }
        default:
            throw std::invalid_argument("Something went wrong");
    }
}

void ComparingFiguresScreen::display() {
    cout << "Computer is choosing..." << std::endl;
    cout << "Computer choose is: " << this->computerFigure->getName() << std::endl;
    if (userFigure->beats(*computerFigure)) {
        cout << "Congratulations! You won!" << std::endl;
        return;
    }
    if (computerFigure->beats(*userFigure)) {
        cout << "Oh no... You lost" << std::endl;
        return;
    }
    cout << "Wow! Draw" << std::endl;
}

void ComparingFiguresScreen::update() {
    cout << "Would you like to try again?" << std::endl;
    cout << TRY_AGAIN_ID << ". Yes" << std::endl;
    cout << EXIT_ID << ". No, exit" << std::endl;
    char choice;
    cin >> choice;
    if (choice != TRY_AGAIN_ID && choice != EXIT_ID) {
        return this->displayUserChoiceError(choice);
    }
    if (choice == EXIT_ID) {
        return this->controller->exitGame();
    }
    SelectFigureScreen* screen = new SelectFigureScreen(this->controller);
    return this->controller->setScreen(screen);
}
