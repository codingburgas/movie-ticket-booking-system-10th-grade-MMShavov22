#include "functions.h"
#include "manager.h"
#include "bookingSystem.h"
#include <iostream>
#include <iomanip> 

BookingSystem::BookingSystem() { }

int BookingSystem::selectCity() {
    std::cout << "Select a city:\n";
    std::cout << "1. City A\n";
    std::cout << "2. City B\n";
    std::cout << "3. City C\n";
    std::cout << "Enter your choice (1-3): ";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 3) ? choice : -1;
}

int BookingSystem::selectCinema(int cityChoice) {
    std::cout << "Select a cinema in City " << cityChoice << ":\n";
    std::cout << "1. Cinema X\n";
    std::cout << "2. Cinema Y\n";
    std::cout << "Enter your choice (1-2): ";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 2) ? choice : -1;
}

int BookingSystem::selectGenre() {
    std::cout << "Select a genre:\n";
    std::cout << "1. Action\n";
    std::cout << "2. Comedy\n";
    std::cout << "3. Drama\n";
    std::cout << "Enter your choice (1-3): ";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 3) ? choice : -1;
}

int BookingSystem::selectMovie(int genreChoice) {
    std::cout << "Select a movie in Genre " << genreChoice << ":\n";
    std::cout << "1. Movie A\n";
    std::cout << "2. Movie B\n";
    std::cout << "Enter your choice (1-2): ";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 2) ? choice : -1;
}

double BookingSystem::calculateTotalPrice(const std::vector<Seat>& selectedSeats) {
    const double silverPrice = 10.0;
    const double goldPrice = 15.0;
    const double platinumPrice = 20.0;

    double totalPrice = 0.0;

    for (const Seat& seat : selectedSeats) {
        switch (seat.type) {
        case SILVER:
            totalPrice += silverPrice;
            break;
        case GOLD:
            totalPrice += goldPrice;
            break;
        case PLATINUM:
            totalPrice += platinumPrice;
            break;
        }
    }

    return totalPrice;
}

void BookingSystem::completeBooking(int cityChoice, int cinemaChoice, int movieChoice, const std::vector<Seat>& selectedSeats, bool isOnlineCustomer) {
    std::cout << "Booking completed successfully!\n";
    std::cout << "City: " << cityChoice << "\n";
    std::cout << "Cinema: " << cinemaChoice << "\n";
    std::cout << "Movie: " << movieChoice << "\n";
    std::cout << "Number of seats booked: " << selectedSeats.size() << "\n";
    std::cout << "Total Price: $" << std::fixed << std::setprecision(2) << calculateTotalPrice(selectedSeats) << "\n";
    if (isOnlineCustomer) {
        std::cout << "Booking type: Online\n";
    }
    else {
        std::cout << "Booking type: In-person\n";
    }
}

void BookingSystem::printBookingDetails(int cityChoice, int cinemaChoice, int movieChoice) {
    std::cout << "Booking Details:\n";
    std::cout << "City: " << cityChoice << "\n";
    std::cout << "Cinema: " << cinemaChoice << "\n";
    std::cout << "Movie: " << movieChoice << "\n";
}

double BookingSystem::calculateTotalPrice(const std::vector<Seat>& selectedSeats) {
    const double pricePerSeat = 10.0; // Example price per seat
    return selectedSeats.size() * pricePerSeat;
}