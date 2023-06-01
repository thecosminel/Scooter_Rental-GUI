#ifndef SCOOTER_RENTAL_GUI_UI_ENTERDATA_H
#define SCOOTER_RENTAL_GUI_UI_ENTERDATA_H

#include "data_validation_functions.h"
#include "../Domain/Scooter.h"

#include <iostream>

using namespace utils;
using scooter::ScooterStatus, scooter::PARKED, scooter::MAINTENANCE, scooter::RESERVED;
using scooter::IN_USE, scooter::OUT_OF_SERVICE, scooter::UNKNOWN;
using std::endl, std::cout, std::string, std::cin;

namespace utils {



    string enterUserName();

    string enterPassword();

    void pressEnterToContinue();

    // For scooter attributes
    string enterModel();
    string enterManufacturingDate();
    double enterKm();
    string enterLocation();
    ScooterStatus enterStatus();

} // utils

#endif //SCOOTER_RENTAL_GUI_UI_ENTERDATA_H
