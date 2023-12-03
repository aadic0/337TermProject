#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <string>

int menu();
void displayFlightSeatMap(int numCols, int numRows, std::vector<std::vector<std::string>> seatMap);
void displayPassengerInformation(std::vector<std::string>firstName, std::vector<std::string>lastName, std::vector<std::string>phone, std::vector<std::string>row, std::vector<std::string>seat, std::vector<std::string>ID);
void addPassenger(std::vector<std::string>& lastNames, std::vector<std::string>& firstNames, std::vector<std::string>& phoneNumbers, std::vector<std::string>& seatNumbers, std::vector<std::string>& passengerIDs, std::vector<std::vector<std::string>>& seatMap, int numCol, int numRow, std::vector<std::string>& rowNum, std::vector<std::string>& columnLetter);
void removePassenger(std::vector<std::string>& lastNames, std::vector<std::string>& firstNames, std::vector<std::string>& phoneNumbers, std::vector<std::string>& seatNumbers, std::vector<std::string>& passengerIDs, std::vector<std::vector<std::string>>& seatMap, std::vector<std::string>& rowNum, std::vector<std::string>& columnLetter, const std::string& ID);


#endif