#include "Airline.h"


Airline::Airline(std::string AirlineNameInput, std::vector<std::string> FlightListInput, int FlightNumberInput){

    AirlineName = AirlineNameInput;
    FlightList = FlightListInput;
    FlightNumber = FlightNumberInput;

}

Airline::Airline(const Airline& src){

    AirlineName = src.AirlineName;
    FlightList = src.FlightList;
    FlightNumber = src.FlightNumber;

}

Airline& Airline::operator=(const Airline& rhs){

    if (this != &rhs){

        AirlineName = rhs.AirlineName;
        FlightList = rhs.FlightList;
        FlightNumber = rhs.FlightNumber;

    }
    return *this;

}
