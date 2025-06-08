#pragma once

#include "structs.h"

class SeatingManager {
public:
    SeatingLayout createSampleLayout();
    void displayLayout(const SeatingLayout& layout);
    void bookSeats(SeatingLayout& layout);
};