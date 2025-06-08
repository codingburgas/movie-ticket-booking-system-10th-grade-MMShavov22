#include "seatingManager.h"
#include "manager.h"

SeatingLayout SeatingManager::createSampleLayout() {
    SeatingLayout layout;
    layout.seats = {
        { Seat(false), Seat(false), Seat(false) },
        { Seat(false), Seat(false), Seat(false) },
        { Seat(false), Seat(false), Seat(false) }
    };
    return layout;
}

void SeatingManager::displayLayout(const SeatingLayout& layout) {
    for (const auto& row : layout.seats) {
        for (const auto& seat : row) {
            std::cout << (seat.isBooked ? "[X]" : "[ ]") << " ";
        }
        std::cout << "\n";
    }
}

void SeatingManager::bookSeats(SeatingLayout& layout) {
    int row, col;
    std::cout << "Enter row and column to book (e.g., 1 2): ";
    std::cin >> row >> col;
    if (row >= 1 && row <= layout.seats.size() && col >= 1 && col <= layout.seats[0].size()) {
        layout.seats[row - 1][col - 1].isBooked = true;
    }
    else {
        std::cout << "Invalid seat selection.\n";
    }
}