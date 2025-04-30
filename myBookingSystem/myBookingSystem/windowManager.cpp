#include <iostream>
#include <fstream>
#include "manager.h"

void drawScene() {
    int input;
    print("./assets/menus/MainMenu.txt");
    std::cin >> input;
    switch (input) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        exitMessage();
        break;
    }
}