#include "seatingManager.h"
#include "bookingSystem.h"
#include "loginValid.h"
#include "userManager.h"
#include "manager.h"
#include <fstream>

void Start() {
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
}

void mainMenu() {
    BookingSystem bookingSystem;
    SeatingManager seatingManager;

    while (true) {
        clearScreen();
        print("logo.txt");

        std::cout << "1. Start Booking\n";
        std::cout << "2. Log out\n";

        int menuChoice = 0;
        std::cout << "Choice (1-2): ";
        std::cin >> menuChoice;

        if (menuChoice == 2) {
            break;
        }

        if (menuChoice == 1) {
            int cityChoice = bookingSystem.selectCity();
            if (cityChoice == -1) {
                continue;
            }

            int cinemaChoice = bookingSystem.selectCinema(cityChoice);
            if (cinemaChoice == -1) {
                continue;
            }

            int genreChoice = bookingSystem.selectGenre();
            if (genreChoice == -1) {
                continue;
            }

            int movieChoice = bookingSystem.selectMovie(genreChoice);
            if (movieChoice == -1) {
                continue;
            }

            bookingSystem.printBookingDetails(cityChoice, cinemaChoice, movieChoice);

            SeatingLayout layout = seatingManager.createSampleLayout();
            seatingManager.displayLayout(layout);

            seatingManager.bookSeats(layout);

            seatingManager.displayLayout(layout);

            std::vector<Seat> bookedSeats;
            for (int i = 0; i < layout.seats.size(); i++) {
                for (int j = 0; j < layout.seats[i].size(); j++) {
                    if (layout.seats[i][j].isBooked) {
                        bookedSeats.push_back(layout.seats[i][j]);
                    }
                }
            }

            bool isOnlineCustomer = false;
            bookingSystem.completeBooking(cityChoice, cinemaChoice, movieChoice, bookedSeats, isOnlineCustomer);
        }
        else {
            clearScreen();
        }
    }
}

void showMainMenu() {
    printFile("assets/menus/mainMenu.txt");
    std::cout << "Choose an option: ";
}