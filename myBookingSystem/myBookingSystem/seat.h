#pragma once
#include "structs.h" 

class Seat {
public:
    int row;          
    int col;         
    SeatType type;    
    bool isBooked;    

    Seat(int r = 0, int c = 0, SeatType t = SILVER, bool booked = false)
        : row(r), col(c), type(t), isBooked(booked) {
    }
};