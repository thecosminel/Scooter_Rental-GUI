#ifndef SCOOTER_RENTAL_GUI_UI_PRINTFUNCTIONS_H
#define SCOOTER_RENTAL_GUI_UI_PRINTFUNCTIONS_H

#include <iostream>
#include "../Domain/Scooter.h"

using std::cout, std::endl, std::string;
using scooter::ScooterStatus;

namespace utils {

    /// Print indexing
    /// \param index
    void printIndexing(int index);

    /// Insert blank
    /// \param text
    void insertBlankSpaces(const string& text);

    /// Print double
    /// \param number
    void printDoubleNumber(double number);

    /// Print status
    /// \param status
    /// \return
    string getScooterStatusString(ScooterStatus status);

} // utils

#endif //SCOOTER_RENTAL_GUI_UI_PRINTFUNCTIONS_H
