#include <string>
#include <iostream>
#include "screen.h"
#include "../figure.h"
using std::string;
using std::cout;
using std::cin;

void SelectFigureScreen::display() {
    this->clearScreen();
    cout << "Select one of figures below" << std::endl;
    cout << this->ROCK_ID << ". Rock" << std::endl;
    cout << this->PAPER_ID << ". Paper" << std::endl;
    cout << this->SCISSORS_ID << ". Scissors" << std::endl;
}

void SelectFigureScreen::update() {
    char choice;
    cin >> choice;
    if (choice != ROCK_ID && choice != PAPER_ID && choice != SCISSORS_ID) {
        return this->displayUserChoiceError(choice);
    }
    IFigure* userFigure = this->getFigure(choice);
    this->clearScreen();
    cout << "You have choosen a " << userFigure->getName() << std::endl;
    ComparingFiguresScreen* screen = new ComparingFiguresScreen(this->controller, userFigure);
    return this->controller->setScreen(screen);
}

IFigure* SelectFigureScreen::getFigure(char code) {
    switch (code) {
        case ROCK_ID:
            return new Rock();
            break;
        case PAPER_ID:
            return new Paper();
            break;
        case SCISSORS_ID:
            return new Scissors();
        default:
            throw std::invalid_argument("There is no such figure");
            break;
    }
}
