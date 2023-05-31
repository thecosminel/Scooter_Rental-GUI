#ifndef SCOOTER_RENTAL_GUI_ABSTRACTUI_H
#define SCOOTER_RENTAL_GUI_ABSTRACTUI_H

#include "../Domain/Scooter.h"

#include <vector>
#include <string>

using scooter::Scooter;
using std::vector, std::string;

namespace ui {

    class AbstractUI {

    public:
        // ------------------------
        // Constructors & destructors
        /// Default constructor
        AbstractUI() = default;

        /// Default copy constructor
        /// \param ui
        AbstractUI(const AbstractUI &ui) = default;

        /// Default assigment operator constructor
        /// \param ui
        /// \return
        AbstractUI &operator=(const AbstractUI &ui) = default;

        /// Default destructor
        ~AbstractUI() = default;

        // ------------------------
        // Printing methods
        virtual void printScooterContainer(vector<Scooter>) = 0;

        virtual void printMessage(string message) = 0;


    };

} // ui

#endif
