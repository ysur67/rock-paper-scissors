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
    while (true) {
        controller.update();
    }
    return 0;
}
