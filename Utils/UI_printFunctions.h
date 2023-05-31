#ifndef SCOOTER_RENTAL_GUI_UI_PRINTFUNCTIONS_H
#define SCOOTER_RENTAL_GUI_UI_PRINTFUNCTIONS_H

#include <iostream>
#include "../Domain/Scooter.h"

using std::cout, std::endl, std::string;
using scooter::ScooterStatus;

namespace utils {

    void printIndexing(int index);

    void insertBlankSpaces(const string& text);

    void printDoubleNumber(double number);

    string getScooterStatusString(ScooterStatus status);

} // utils

#endif //SCOOTER_RENTAL_GUI_UI_PRINTFUNCTIONS_H
