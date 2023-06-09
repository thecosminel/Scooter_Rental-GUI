#ifndef SCOOTER_RENTAL_GUI_ABSTRACTUI_H
#define SCOOTER_RENTAL_GUI_ABSTRACTUI_H

#include "../Domain/Scooter.h"

#include <vector>
#include <string>

using scooter::Scooter;
using std::vector, std::string, std::pair;

namespace ui {

    class AbstractUI {
    protected:
        string user;
        string password;
        Scooter currentScooter;

    public:
        // ------------------------
        // Constructors & destructors
        /// Default constructor
        AbstractUI();

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
        /// Print scooter container define
        virtual void updateScooterContainer(vector<Scooter>) = 0;
        /// Print message
        /// \param message
        virtual void updateMessage(string message) = 0;

        // Getters & setters
        /// Get current
        /// \param identifier
        virtual void getCurrentScooter(string identifier) = 0;
        /// Set current
        /// \param scooter
        virtual void setCurrentScooter(Scooter scooter) = 0;

    };

} // ui

#endif
