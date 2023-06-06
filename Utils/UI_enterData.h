#ifndef SCOOTER_RENTAL_GUI_UI_ENTERDATA_H
#define SCOOTER_RENTAL_GUI_UI_ENTERDATA_H

#include "data_validation_functions.h"
#include "../Domain/Scooter.h"

#include <iostream>

using namespace utils;
using scooter::ScooterStatus, scooter::PARKED, scooter::MAINTENANCE, scooter::RESERVED;
using scooter::IN_USE, scooter::OUT_OF_SERVICE, scooter::UNKNOWN;
using std::endl, std::cout, std::string, std::cin, std::pair;

namespace utils {
    /// Enter user
    /// \return
    string enterUserName();
    /// Enter pass
    /// \return
    string enterPassword();
    /// Press enter to cont
    void pressEnterToContinue();

    // For scooter attributes
    /// Enter id
    /// \return
    string enterID();
    /// Enter model
    /// \return
    string enterModel();
    /// Enter manufacturing date
    /// \return
    string enterManufacturingDate();
    /// Enter manufacturing dates
    /// \return
    pair <string, string> enterManufacturingDates();
    /// Enter km
    /// \return
    double enterKm();
    /// Enter km
    /// \return
    pair <double, double> enterKmMultiple();
    /// Enter location
    /// \return
    string enterLocation();
    /// Enter status
    /// \return
    ScooterStatus enterStatus();


} // utils

#endif //SCOOTER_RENTAL_GUI_UI_ENTERDATA_H
