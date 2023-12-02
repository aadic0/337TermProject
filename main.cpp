#include <iostream>
#include "main.h"
#include "Airline.h"
#include "Flight.h"
#include "Passenger.h"
#include "seat.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){

    cout << "Term Project - Flight Management Program" << endl;
    cout << "Produced by Aadi Chauhan" << endl;

    cout << endl;

    ifstream info("flight_info.txt");
    string flight_details;
    getline(info, flight_details);
    istringstream iss(flight_details);
    string flightID;
    int numRow, numCol;

    iss >> flightID >> numRow >> numCol;

    
    string line;
    vector<string> lastNames;
    vector<string> firstNames;
    vector<string> phoneNumbers;
    vector<string> seatNumbers;
    vector<string> passengerIDs;

    string lastName;
    string firstName;
    string phoneNumber;
    string seatNumber;
    string passengerID;

    while (!info.eof()) {

        getline(info, lastName);
        getline(info, firstName);
        getline(info, phoneNumber);
        getline(info, seatNumber);
        getline(info, passengerID);

        lastNames.push_back(lastName);
        firstNames.push_back(firstName);
        phoneNumbers.push_back(phoneNumber);
        seatNumbers.push_back(seatNumber);
        passengerIDs.push_back(passengerID);

        }

    info.close();



    vector<vector<string>> seatMap(numRow, vector<string>(numCol, " "));

for (size_t i = 0; i < seatNumbers.size(); ++i) {
    string seatNumber = seatNumbers[i];

    char col = seatNumber.back();
    int row = stoi(seatNumber.substr(0, seatNumber.size() - 1)) - 1;

    if (col >= 'A' && col < 'A' + numCol && row >= 0 && row < numRow) {
        seatMap[row][col - 'A'] = "X";
    }
}


    int decision;
    do
    {
        decision = menu();

        switch (decision)
        {
        case 1:
            displayFlightSeatMap(numRow, numCol, seatMap);
            break;

        case 2:
            break;

        case 3:
            //
            break;

        case 4:
            //
            break;

        case 5:
            //
            break;
        
        case 6:
            decision = 0;
            break;
        
        default:
            cout <<"You have entered in an invalid number, try again: " << endl;
            break;
    }



    } while (decision != 0);

}

int menu(){

    cout << "Please select one of the options:" << endl;
    cout << endl;

    cout << "1. Display Flight Seat Map" << endl;
    cout << "2. Display Passengers Information" << endl;
    cout << "3. Add a New Passenger" << endl;
    cout << "4. Remove an existing passenger" << endl;
    cout << "5. Save data" << endl;
    cout << "6. Quit" << endl;

    int decision;

    cout << "Enter your choice (1, 2, 3, 4, 5, 6):" << endl;
    cin >> decision;
    return decision;    

}

#include <iostream>

void displayFlightSeatMap(int numCols, int numRows, vector<vector<string>> seatMap) {
    int temp;
    temp = numRows;
    numRows = numCols;
    numCols = temp;

    cout << endl;
    cout << " ";

    for (int j = 0; j <= 4 * numCols; j++) {
        if (j % 4 == 2)
            cout << char('A' + j / 4);
        else
            cout << " ";
    }

    cout << endl;

    for (int i = 0; i <= 2 * numRows; i++) {
        if (i % 2 != 0)
            cout << 1 + i / 2;

        for (int j = 0; j <= 2 * numCols; j++) {
            if (i % 2 == 0) {
                if (j == 0)
                    cout << " ";
                if (j % 2 == 0)
                    cout << " ";
                else
                    cout << "---";
            } else {
                if (j % 2 == 0)
                    cout << "|";
                else {
                    if (seatMap[i/2][j/2] == "X")
                        cout << " X ";
                    else
                        cout << "   ";
                }
            }
        }

        if (i % 2 != 0)
            cout << 1 + i / 2;

        cout << endl;
    }

    cout << " ";
    for (int j = 0, i = 1; j <= 4 * numCols; j++) {
        if (j % 4 == 2)
            cout << char('A' + j / 4);
        else
            cout << " ";
    }

    cout << endl;
}



