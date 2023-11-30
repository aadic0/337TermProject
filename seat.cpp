#include "seat.h"

using namespace std;

Seat::Seat(int RowSInput, int ColumnSInput, int AvailabilityInput){

    RowS = RowSInput;
    ColumnSInput = ColumnSInput;
    Availability = AvailabilityInput;

}

Seat::Seat(const Seat &src){

    RowS = src.RowS;
    ColumnS = src.ColumnS;
    Availability = src.Availability;

}

Seat& Seat::operator=(const Seat& rhs){

    if (this != &rhs){

        RowS = rhs.RowS;
        ColumnS = rhs.ColumnS;
        Availability = rhs.Availability;

    }

}