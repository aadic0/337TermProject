#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"


class Passenger{

    public:
        // constructors
        Passenger(int PassengerIdInput, std::string FirstNameInput, std::string LastNameInput, int PhoneNumberInput, int RowP, int ColumnP, Flight& flight);
        Passenger(const Passenger& src);
        Passenger& operator=(const Passenger& rhs);
        ~Passenger();

        // getter functions
        inline int getPassengerId() {return PassengerId;}
        inline std::string getFirstName() {return FirstName;}
        inline std::string getLastName() {return LastName;}
        inline int getPhoneNumber() {return PhoneNumber;}
        inline std::string* getPassengerSeat() {return PassengerSeat;}


    private:
        int PassengerId;
        std::string FirstName;
        std::string LastName;
        int PhoneNumber;
        std::string* PassengerSeat;
        
};


#endif