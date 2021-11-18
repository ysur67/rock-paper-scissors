#include <string>
#include <iostream>
#include "screen.h"
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
    switch (choice) {
        case ROCK_ID:
            cout << std::endl;
            break;
        default:
            cout << std::endl;
            break;
    }
}
