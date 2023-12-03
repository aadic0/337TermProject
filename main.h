#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <string>

int menu();
void displayFlightSeatMap(int numCols, int numRows, std::vector<std::vector<std::string>> seatMap);
void displayPassengerInformation(std::vector<std::string>firstName, std::vector<std::string>lastName, std::vector<std::string>phone, std::vector<std::string>row, std::vector<std::string>seat, std::vector<std::string>ID);


#endif