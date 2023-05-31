#ifndef SCOOTER_RENTAL_GUI_CONCRETEUI_H
#define SCOOTER_RENTAL_GUI_CONCRETEUI_H

#include "../AbstractUI.h"
#include "../../Utils/UI_printFunctions.h"

#include <iostream>

using ui::AbstractUI;
using namespace utils;
using std::cout, std::endl;

namespace ui {

    class ConcreteUI : public AbstractUI{
    public:
        // ------------------------
        // Constructors & destructors
        /// Default constructor
        ConcreteUI() = default;

        /// Default copy constructor
        /// \param ui
        ConcreteUI(const ConcreteUI &ui) = default;

        /// Default assigment operator constructor
        /// \param ui
        /// \return
        ConcreteUI &operator=(const ConcreteUI &ui) = default;

        /// Default destructor
        ~ConcreteUI() = default;

        // Printing methods
        void printScooterContainer(vector<Scooter> scooters) override;

        void printMessage(string message) override;

        // ------------------------
        // Non override
//        void printScootersSortedByID();

//        void printScootersSortedByManufacturingDate();
    };

} // ui

#endif //SCOOTER_RENTAL_GUI_CONCRETEUI_H
