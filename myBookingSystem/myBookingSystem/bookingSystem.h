#pragma once

#include <vector>
#include <string>
#include "seat.h"

class BookingSystem {
public:
    int selectCity();
    int selectCinema(int cityChoice);
    int selectGenre();
    int selectMovie(int genreChoice);
    void printBookingDetails(int cityChoice, int cinemaChoice, int movieChoice);
    void completeBooking(int cityChoice, int cinemaChoice, int movieChoice, const std::vector<Seat>& bookedSeats, bool isOnlineCustomer);
};