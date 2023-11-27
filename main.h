#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>


class Airline{

    public:
        // constructors
        Airline(std::string AirlineNameInput, std::vector<std::string> FlightListInput, int FlightNumberInput);
        Airline(const Airline& src);
        Airline& operator=(const Airline& rhs);
        ~Airline() = delete; 

        // getter functions
        inline std::string getAirlineName() {return AirlineName;}
        inline std::vector<std::string> getFlightList() {return FlightList;}
        inline int getFlightNumber() {return FlightNumber;}

        // setter functions
        inline std::string setAirlineName(std::string name) {AirlineName = name;}
        inline std::vector<std::string> setFlightList(std::vector<std::string> list) {FlightList = list;}
        inline int setFlightNumber(int number) {FlightNumber = number;}

    private:
        std::string AirlineName;
        std::vector<std::string> FlightList;
        int FlightNumber; 
};

class Flight{

    public:
        // constructors
        Flight();
        Flight(Flight& src);
        Flight& operator=(Flight& rhs);
        ~Flight();

        // getter functions
        inline int getRowsF() {return RowsF;}
        inline int getColumnsF() {return ColumnsF;}
        inline std::vector<std::string> getPassengerList() {return PassengerList;}
        inline std::vector<std::vector<std::string>> getSeatMap() {return SeatMap;}

        // setter functions
        inline int setRowsF(int number) {RowsF = number;}
        inline int setColumnsF(int number) {ColumnsF = number;}
        inline std::vector<std::string> setPassengerList(std::vector<std::string> list) {PassengerList = list;}
        inline std::vector<std::vector<std::string>> setSeatMap(std::vector<std::vector<std::string>> input) {SeatMap = input;}

    private:
        std::string FlightID;
        int RowsF;
        int ColumnsF;
        std::vector<std::string> PassengerList;
        std::vector<std::vector<std::string>> SeatMap; 

};

class Passenger{

    public:
        // constructors
        Passenger(int PassengerIdInput, std::string FirstNameInput, std::string LastNameInput, int PhoneNumberInput, Flight*** PassengerSeatInput);
        Passenger(Passenger& src);
        Passenger& operator=(Passenger& rhs);
        ~Passenger();

        // getter functions
        inline int getPassengerId() {return PassengerId;}
        inline std::string getFirstName() {return FirstName;}
        inline std::string getLastName() {return LastName;}
        inline int getPhoneNumber() {return PhoneNumber;}
        inline Flight*** getPassengerSeat() {return PassengerSeat;}


    private:
        int PassengerId;
        std::string FirstName;
        std::string LastName;
        int PhoneNumber;
        Flight*** PassengerSeat;
        
};


class Seat{

    public:
        // constructors
        Seat();
        Seat(Seat& src);
        Seat& operator=(Seat& rhs);
        ~Seat();


    private:
        int RowS;
        int ColumnS;
        int Availability;

};

#endif
