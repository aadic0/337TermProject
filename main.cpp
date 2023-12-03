#include <iostream>
#include "Airline.h"
#include "Flight.h"
#include "Passenger.h"
#include "seat.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "main.h"

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

    vector<string> temp = lastNames;
    lastNames = firstNames;
    firstNames = temp;

    vector<string> rowNum, seatLetter;

    for (int i = 0; i < seatNumbers.size(); i++){

        rowNum.push_back(seatNumbers[i].substr(0, seatNumbers[i].size()-1));
        seatLetter.push_back(seatNumbers[i].substr(seatNumbers[i].size() -1 , 1));

    }




    int decision;
    char inputBuffer;
    do
    {
        decision = menu();
        string IDremove;

        switch (decision)
        {
        case 1:
            displayFlightSeatMap(numRow, numCol, seatMap);
            break;

        case 2:
            displayPassengerInformation(firstNames, lastNames, phoneNumbers, rowNum, seatLetter, passengerIDs);
            break;

        case 3:
            addPassenger(lastNames, firstNames, phoneNumbers, seatNumbers, passengerIDs, seatMap, numCol, numRow, rowNum, seatLetter);
            cout << endl;
            cout << "Successfully added" << endl;
            break;

        case 4:
            cout << "Please enter the id of the passenger that needs to be removed: " << endl;
            cin >> IDremove;
            inputBuffer = cin.get();

            removePassenger(lastNames, firstNames, phoneNumbers, seatNumbers, passengerIDs, seatMap, rowNum, seatLetter, IDremove);

            break;

        case 5:
            saveData("flight_info.txt", flightID, numRow, numCol, lastNames, firstNames, phoneNumbers, seatNumbers, passengerIDs);
            cout << "Data saved successfully." << endl;
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

void displayPassengerInformation(vector<string>firstName, vector<string>lastName, vector<string>phone, vector<string>row, vector<string>seat, vector<string>ID){
    cout << endl;


    // Print the header
    cout << left << setw(16) << "First Name" << setw(16) << "Last Name" << setw(16) << "Phone" << setw(6) << "Row" << setw(6) << "Seat" << setw(11) << "ID" << endl;

    // Print the data
    for(int i = 0; i < firstName.size(); i++) {
        cout << setw(16) << firstName[i] << setw(16) << lastName[i] << setw(16) << phone[i] << setw(6) << row[i] << setw(6) << seat[i] << setw(11) << ID[i] << endl;
    }

    cout << endl;

}

void addPassenger(vector<string>& lastNames, vector<string>& firstNames, vector<string>& phoneNumbers, vector<string>& seatNumbers, vector<string>& passengerIDs, vector<vector<string>>& seatMap, int numCol, int numRow, vector<string>& rowNum, vector<string>& columnLetter){

    string firstName;
    string lastName;
    string phone;
    string seat;
    string ID;
    char inputBuffer;

    cout << endl;

    cout << "What is the first name of the passenger you want to add:" <<  endl;
    cin >> firstName;
    inputBuffer = cin.get();

    cout << "What is the last name of the passenger you want to add:" << endl;
    cin >> lastName;
    inputBuffer = cin.get();

    cout << "What is the phone number of the passenger (XXX-XXX-XXXX, where X is a number):" << endl;
    cin >> phone;
    inputBuffer = cin.get();

    cout << "What seat number are they registered for (XXY or XY, where X is a number, and Y is a capital letter): " << endl;
    cin >> seat;
    inputBuffer = cin.get();


    cout << "What is their ID number (XXXXX where X is a number):" << endl;
    cin >> ID;
    inputBuffer = cin.get();
    
    

    lastNames.push_back(lastName);
    firstNames.push_back(firstName);
    phoneNumbers.push_back(phone);
    seatNumbers.push_back(seat);
    passengerIDs.push_back(ID);

    for (size_t i = 0; i < seatNumbers.size(); ++i) {
        string seatNumber = seatNumbers[i];

        char col = seatNumber.back();
        int row = stoi(seatNumber.substr(0, seatNumber.size() - 1)) - 1;

        if (col >= 'A' && col < 'A' + numCol && row >= 0 && row < numRow) {
            seatMap[row][col - 'A'] = "X";
        }
    }

    string row = seat.substr(0, seat.size()-1);
    string column = seat.substr(seat.size()-1, 1);

    rowNum.push_back(row);
    columnLetter.push_back(column);


}

void removePassenger(vector<string>& lastNames, vector<string>& firstNames, vector<string>& phoneNumbers, vector<string>& seatNumbers, vector<string>& passengerIDs, vector<vector<string>>& seatMap, vector<string>& rowNum, vector<string>& columnLetter, const string& ID) {
    // Find the index of the passenger with the given ID
    int index = -1;
    for (int i = 0; i < passengerIDs.size(); i++) {
        if (passengerIDs[i] == ID) {
            index = i;
            break;
        }
    }

    // If the passenger is not found, print an error message and return
    if (index == -1) {
        cout << "Passenger with ID " << ID << " not found." << endl;
        return;
    }

    // Update the seat map
    string seatNumber = seatNumbers[index];
    char col = seatNumber.back();
    int row = stoi(seatNumber.substr(0, seatNumber.size() - 1)) - 1;
    if (col >= 'A' && col < 'A' + seatMap[0].size() && row >= 0 && row < seatMap.size()) {
        seatMap[row][col - 'A'] = " ";
    }

    // Remove the passenger's details from the vectors
    lastNames.erase(lastNames.begin() + index);
    firstNames.erase(firstNames.begin() + index);
    phoneNumbers.erase(phoneNumbers.begin() + index);
    seatNumbers.erase(seatNumbers.begin() + index);
    passengerIDs.erase(passengerIDs.begin() + index);
    rowNum.erase(rowNum.begin() + index);
    columnLetter.erase(columnLetter.begin() + index);

    cout << "Successfully removed passenger with ID " << ID << "." << endl;
}

void saveData(const string& filename, const string& flightID, int numRow, int numCol, const vector<string>& lastNames, const vector<string>& firstNames, const vector<string>& phoneNumbers, const vector<string>& seatNumbers, const vector<string>& passengerIDs) {
    
    ofstream outFile(filename);

    outFile << flightID << " " << numRow << " " << numCol << endl;

    for (int i = 0; i < lastNames.size(); i++) {
        outFile << firstNames[i] << endl;
        outFile << lastNames[i] << endl;
        outFile << phoneNumbers[i] << endl;
        outFile << seatNumbers[i] << endl;
        outFile << passengerIDs[i] << endl;
    }

    outFile.close();
}
