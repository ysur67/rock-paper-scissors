#include <string>
#include <iostream>
#include "figure.h"
#include "screens/screen.h"
#include "screens/controller.h"
using std::cout;
using std::cin;
using std::string;


int main() {
    GameController controller = GameController();
    MainMenu menu = MainMenu(&controller);
    controller.setScreen(&menu);
    while (true) {
        controller.update();
    }
    return 0;
}
