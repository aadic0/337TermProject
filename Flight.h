#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <vector>

class Flight{

    public:
        // constructors
        Flight(std::string FlightIDInput, int RowsInput, int ColumnsInput, std::vector<std::string> PassengerListInput, std::vector<std::vector<std::string>> SeatMapInput);
        Flight(const Flight& src);
        Flight& operator=(const Flight& rhs);
        ~Flight() {delete this;}

        // getter functions
        inline std::string getFlightID() {return FlightID;}
        inline int getRowsF() {return RowsF;}
        inline int getColumnsF() {return ColumnsF;}
        inline std::vector<std::string> getPassengerList() {return PassengerList;}
        inline std::vector<std::vector<std::string>> getSeatMap() {return SeatMap;}

        // setter functions
        inline std::string setFlightID(std::string sid) {FlightID = sid;}
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



#endif