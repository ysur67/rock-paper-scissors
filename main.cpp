#include <string>
#include <iostream>
#include "figure.h"
using std::cout;
using std::cin;
using std::string;


int main() {
    cout << std::endl << "ROCK-PAPER-SCISSORS" << std::endl;
    bool isGameFinished = false;
    const int ROCK_ID = '1';
    const int PAPER_ID = '2';
    const int SCISSORS_ID = '3';
    const int EXIT_ID = '4';
    while (!isGameFinished) {
        cout << std::endl;
        cout << (char)ROCK_ID << ". Rock" << std::endl;
        cout << (char)PAPER_ID << ". Paper" << std::endl;
        cout << (char)SCISSORS_ID << ". Scissors" << std::endl;
        cout << (char)EXIT_ID <<". Exit the game" << std::endl;
        cout << "Select your figure: >> ";
        char userChoice;
        cin >> userChoice;
        cout << std::endl;
        switch (userChoice)
        {
        case ROCK_ID:
            cout << "rock";
            break;
        
        default:
            cout << "Invalid value";
            break;
        }
    }
    return 0;
}
