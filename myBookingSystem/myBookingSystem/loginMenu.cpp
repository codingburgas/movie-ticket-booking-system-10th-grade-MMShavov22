#include "manager.h"

void drawLoginMenu() {

    std::string line;
    std::ifstream loginPage("./assets/menus/LoginMenu.txt");
    if (loginPage.is_open())
    {
        while (getline(loginPage, line))
        {
            std::cout << line << '\n';
        }
        loginPage.close();
    }

}