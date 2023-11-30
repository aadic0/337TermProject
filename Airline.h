#ifndef AIRLINE_H
#define AIRLINE_H


#include <iostream>
#include <string>
#include <vector>

class Airline{

    public:
        // constructors
        Airline(std::string AirlineNameInput, std::vector<std::string> FlightListInput, int FlightNumberInput);
        Airline(const Airline& src);
        Airline& operator=(const Airline& rhs);


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


#endif