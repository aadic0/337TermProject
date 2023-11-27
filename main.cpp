#include <iostream>
#include <vector>
#include <ios>
#include <fstream>
#include <cstdlib>
#include <istream>
#include <ostream>
#include "main.h"

using namespace std;

int main(){




    return 0;
}


/* FUNCTION DEFINITIONS */

// Airline Class
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


