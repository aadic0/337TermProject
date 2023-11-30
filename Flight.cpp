#include "Flight.h"
using namespace std;


Flight::Flight(string FlightIDInput, int RowsInput, int ColumnsInput, vector<string> PassengerListInput, vector<vector<string>> SeatMapInput){

    FlightID = FlightIDInput;
    RowsF = RowsInput;
    ColumnsF = ColumnsInput;
    PassengerList = PassengerListInput;
    SeatMap = SeatMapInput;

}

Flight::Flight(const Flight& src){

    FlightID = src.FlightID;
    RowsF = src.RowsF;
    ColumnsF = src.ColumnsF;
    PassengerList = src.PassengerList;
    SeatMap = src.SeatMap;

}

Flight& Flight::operator=(const Flight& rhs){

    if (this != &rhs){

        FlightID = rhs.FlightID;
        RowsF = rhs.RowsF;
        ColumnsF = rhs.ColumnsF;
        PassengerList = rhs.PassengerList;
        SeatMap = rhs.SeatMap;

    }
    return *this;

}

Flight::~Flight(){
}

