#pragma once

#include "seat.h"
#include <vector>

class SeatingLayout {
public:
    std::vector<std::vector<Seat>> seats;
};

class SeatingManager {
public:
    SeatingLayout createSampleLayout();
    void displayLayout(const SeatingLayout& layout);
    void bookSeats(SeatingLayout& layout);
};