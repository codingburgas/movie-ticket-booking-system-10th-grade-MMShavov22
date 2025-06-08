#pragma once

#include "structs.h"
#include <vector>

class BookingSystem {
public:
    BookingSystem();

    int selectCity();
    int selectCinema(int cityChoice);
    int selectGenre();
    int selectMovie(int genreChoice);

    void completeBooking(int cityChoice, int cinemaChoice, int movieChoice, const std::vector<Seat>& selectedSeats, bool isOnlineCustomer);
    void printBookingDetails(int cityChoice, int cinemaChoice, int movieChoice);

    double calculateTotalPrice(const std::vector<Seat>& selectedSeats);
};