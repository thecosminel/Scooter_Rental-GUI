#ifndef SCOOTER_RENTAL_GUI_AUXILIARYFUNCTIONS_H
#define SCOOTER_RENTAL_GUI_AUXILIARYFUNCTIONS_H

#include "../Domain/Scooter.h"

#include <vector>
#include <iostream>
#include <cctype>
#include <random>

using std::string;

namespace utils {

    /// Checks date format ("dd.mm.year")
    /// \param date
    /// \return true if valid
    bool checkDateFormat(const string& date);

    bool checkIdFormat(const string& ID);


    /// Checks if (date 1 < date 2)
    /// \param date1
    /// \param date2
    /// \return date 1 < date 2
    bool compareDates(const string& date1, const string& date2);

    /// Checks if a string is alphanumeric
    /// \param str
    /// \return true/false
    bool checkAlphanumericString(const string& str);

    bool compareNamesAlphabetically(string name1, string name2);

    string generateRandomID();
}

#endif
