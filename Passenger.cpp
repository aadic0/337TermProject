#include "Passenger.h"


using namespace std;


Passenger::Passenger(int PassengerIdInput, std::string FirstNameInput, std::string LastNameInput, string PhoneNumberInput, int RowPInput, int ColumnPInput, Flight& flight){

    PassengerId = PassengerIdInput;
    FirstName = FirstNameInput;
    LastName = LastNameInput;
    PhoneNumber = PhoneNumberInput;
    rowP = RowPInput;
    columnP = ColumnPInput;
    const string& SeatLoc = flight.getSeatMap()[RowPInput][ColumnPInput];
    PassengerSeat = new string(SeatLoc);
    PassengerSeat = &flight.getSeatMap()[RowPInput][ColumnPInput];


}

Passenger::Passenger(const Passenger& src){

    PassengerId = src.PassengerId;
    FirstName = src.FirstName;
    LastName = src.LastName;
    PhoneNumber = src.PhoneNumber;
    PassengerSeat = src.PassengerSeat;

}

Passenger& Passenger::operator=(const Passenger& rhs){

    if (this != &rhs){

        PassengerId = rhs.PassengerId;
        FirstName = rhs.FirstName;
        LastName = rhs.LastName;
        PhoneNumber = rhs.PhoneNumber;
        PassengerSeat = rhs.PassengerSeat;

    }

    return *this;

}

Passenger::~Passenger(){

    delete PassengerSeat;
    PassengerSeat = nullptr;

}