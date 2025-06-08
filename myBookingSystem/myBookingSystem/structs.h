#pragma once

#include <string>
#include <vector>

struct Cinema {
    std::string name;
};

struct City {
    std::string name;
    std::vector<Cinema> cinemas;
};

struct Movie {
    std::string title;
    std::string genre;
};

enum SeatType {
    SILVER,
    GOLD,
    PLATINUM
};

struct Seat {
    int row;
    int col;
    SeatType type;
    bool isBooked;

    Seat(int r = 0, int c = 0, SeatType t = SILVER, bool booked = false)
        : row(r), col(c), type(t), isBooked(booked) {
    }
};

struct SeatingLayout {
    std::vector<std::vector<Seat>> seats;
};