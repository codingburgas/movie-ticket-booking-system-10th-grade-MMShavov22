#include "bookingSystem.h"
#include "manager.h"

int BookingSystem::selectCity() {
    std::cout << "Select a city:\n1. City A\n2. City B\n3. City C\n";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 3) ? choice : -1;
}

int BookingSystem::selectCinema(int cityChoice) {
    std::cout << "Select a cinema in City " << cityChoice << ":\n1. Cinema X\n2. Cinema Y\n";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 2) ? choice : -1;
}

int BookingSystem::selectGenre() {
    std::cout << "Select a genre:\n1. Action\n2. Comedy\n3. Drama\n";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 3) ? choice : -1;
}

int BookingSystem::selectMovie(int genreChoice) {
    std::cout << "Select a movie in Genre " << genreChoice << ":\n1. Movie A\n2. Movie B\n";
    int choice;
    std::cin >> choice;
    return (choice >= 1 && choice <= 2) ? choice : -1;
}

void BookingSystem::printBookingDetails(int cityChoice, int cinemaChoice, int movieChoice) {
    std::cout << "Booking Details:\n";
    std::cout << "City: " << cityChoice << "\nCinema: " << cinemaChoice << "\nMovie: " << movieChoice << "\n";
}

void BookingSystem::completeBooking(int cityChoice, int cinemaChoice, int movieChoice, const std::vector<Seat>& bookedSeats, bool isOnlineCustomer) {
    std::cout << "Booking completed successfully!\n";
    std::cout << "Seats booked: " << bookedSeats.size() << "\n";
}