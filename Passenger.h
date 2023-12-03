#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"



class Passenger{

    public:
        // constructors
        Passenger(int PassengerIdInput, std::string FirstNameInput, std::string LastNameInput, std::string PhoneNumberInput, int RowP, int ColumnP, Flight& flight);
        Passenger(const Passenger& src);
        Passenger& operator=(const Passenger& rhs);
        ~Passenger();

        // getter functions
        inline int getPassengerId() {return PassengerId;}
        inline std::string getFirstName() {return FirstName;}
        inline std::string getLastName() {return LastName;}
        inline std::string getPhoneNumber() {return PhoneNumber;}
        inline std::string* getPassengerSeat() {return PassengerSeat;}
        inline int getPassengerRow() {return rowP;}
        inline int getPassengerColumn() {return columnP;}

        // setter functions
        inline int setPassengerID(int num) {PassengerId = num;}
        inline std::string setFirstName(std::string name) {FirstName = name;}
        inline std::string setLastName(std::string name) {LastName = name;}
        inline std::string setPhoneNumber(std::string number) {PhoneNumber = number;}
        inline std::string* setPassengerSeat(std::string* place) {PassengerSeat = place;}
        inline int setPassengerRow(int row) {rowP = row;}
        inline int setPassengerColumn(int col) {columnP = col;}

    private:
        int PassengerId;
        std::string FirstName;
        std::string LastName;
        std::string PhoneNumber;
        std::string* PassengerSeat;
        int rowP, columnP;
        
};


#endif