#include <iostream>
#include <fstream>
#include "manager.h"

void drawScene() {
    int input;
    bool logInRegister = 0;
    drawLoginMenu();
    switch (logInRegister) {
    case 0:

        break;
    case 1:
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
}