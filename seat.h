#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"


class Seat{

    public:
        // constructors
        Seat(int RowSInput, int ColumnSInput, int AvailabilityInput);
        Seat(const Seat& src);
        Seat& operator=(const Seat& rhs);
        ~Seat();


    private:
        int RowS;
        int ColumnS;
        int Availability;

};

#endif