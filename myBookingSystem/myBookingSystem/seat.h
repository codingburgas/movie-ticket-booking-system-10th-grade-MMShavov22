#pragma once
#include "structs.h" 

class SeatWrapper : public Seat {
public:
    SeatWrapper(int r = 0, int c = 0, SeatType t = SILVER, bool booked = false)
        : Seat(r, c, t, booked) {
    }
};