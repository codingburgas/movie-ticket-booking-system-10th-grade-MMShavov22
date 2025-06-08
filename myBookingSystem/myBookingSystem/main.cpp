#include "manager.h"
#include "bookingSystem.h"
#include "structs.h"
#include "userManager.h"
#include <limits>

int main() {
	fullScreen();

    std::string username, password;
    bool loggedIn = false;

    printFile("assets/menus/logo.txt");

    while (!loggedIn) {
        std::string loginPromptUser = getLineFromFile("assets/menus/loginMenu.txt", 1);
        std::string loginPromptPass = getLineFromFile("assets/menus/loginMenu.txt", 2);
        std::string userNotFoundMsg = getLineFromFile("assets/menus/loginMenu.txt", 3);
        std::string incorrectPassMsg = getLineFromFile("assets/menus/loginMenu.txt", 4);

        std::cout << "1. Login\n2. Register\nChoose an option: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::cout << loginPromptUser << " ";
            std::getline(std::cin, username);

            if (!findUsername(username)) {
                std::cout << userNotFoundMsg << std::endl;
                continue;
            }

            std::cout << loginPromptPass << " ";
            std::getline(std::cin, password);

            if (fullValidation(username, password)) {
                std::cout << "Login successful!\n";
                loggedIn = true;
            }
            else {
                std::cout << incorrectPassMsg << std::endl;
            }
        }
        else if (choice == 2) {
            std::cout << "Choose a username: ";
            std::getline(std::cin, username);

            if (findUsername(username)) {
                std::cout << "Username already exists. Try a different one.\n";
                continue;
            }

            std::cout << "Choose a password: ";
            std::getline(std::cin, password);

            createNewUser(username, password);
            std::cout << "Registration successful! You can now log in.\n";
        }
        else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    bool running = true;
    while (running) {
        showMainMenu();
        int menuChoice;
        std::cin >> menuChoice;
        std::cin.ignore();

        switch (menuChoice) {
        case 1:
            bookSeat();
            break;
        case 2:
            std::cout << "Exiting program. Goodbye!\n";
            running = false;
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}