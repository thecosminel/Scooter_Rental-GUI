#ifndef SCOOTER_RENTAL_GUI_AUXILIARYFUNCTIONS_H
#define SCOOTER_RENTAL_GUI_AUXILIARYFUNCTIONS_H

#include "../Domain/Scooter.h"

#include <vector>
#include <iostream>
#include <cctype>
#include <random>

using std::string;
using scooter::Scooter;

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

    /// Checks if (date 1 < date 2)
    /// \param scooter1
    /// \param scooter2
    /// \return date 1 < date 2
    bool compareScooterByDate(const Scooter& scooter1, const Scooter& scooter2);
    /// Compare model
    /// \param scooter1
    /// \param scooter2
    /// \return
    bool compareScooterByModel(const Scooter& scooter1, const Scooter& scooter2);
    /// Compare km
    /// \param scooter1
    /// \param scooter2
    /// \return
    bool compareScooterByKm(const Scooter& scooter1, const Scooter& scooter2);
    /// Compare location
    /// \param scooter1
    /// \param scooter2
    /// \return
    bool compareScooterByLocation(const Scooter& scooter1, const Scooter& scooter2);
    /// Compare status
    /// \param scooter1
    /// \param scooter2
    /// \return
    bool compareScooterByStatus(const Scooter& scooter1, const Scooter& scooter2);


    /// Checks if a string is alphanumeric
    /// \param str
    /// \return true/false
    bool checkAlphanumericString(const string& str);

    /// Compare two strings lexicographically
    /// \param name1
    /// \param name2
    /// \return
    bool compareStringsAlphabetically(string name1, string name2);

    /// Generate random id of 3 letters
    string generateRandomID();

    /// Generate access key (not needed anymore)
    /// \return
    string generateAccessKey();

    /// Convert double to string (only 2 digits after .)
    /// \param value
    /// \return
    string doubleToString(double value);
}

#endif
