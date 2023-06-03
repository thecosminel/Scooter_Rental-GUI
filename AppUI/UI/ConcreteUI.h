#ifndef SCOOTER_RENTAL_GUI_CONCRETEUI_H
#define SCOOTER_RENTAL_GUI_CONCRETEUI_H

#include "../AbstractUI.h"
#include "../../Utils/UI_printFunctions.h"
#include "../ISubject.h"

#include <iostream>

using ui::AbstractUI;
using namespace utils;
using std::cout, std::endl;

namespace ui {

    class ConcreteUI : public AbstractUI, public ISubject{
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

        // Getters & setters
        void getCurrentScooter(string identifier) override;
        void setCurrentScooter(Scooter scooter) override;

        // ------------------------
        // ISubject

        void tryToLogAsManager(string user, string pass) override;
        void tryToLogAsUser(string user, string pass) override;
        void createUserAccount(string user, string pass) override;

        void requestScooter (string identifier) override;

        void callCUD(Operations operation, const Scooter &scooter) override;

        void callRUP(Operations operation, const Scooter &scooter, string user) override;

        void callVectorAllScootersOfUser(string userName) override;

        void callVectorSort(Operations operation) override;

        void callFilterLocation(Operations operations, string location) override;

        void callFilterDates(Operations operation, std::pair<string, string> dates) override;

        void callFilterKm(Operations operation, std::pair<double, double> km) override;
    };

} // ui

#endif //SCOOTER_RENTAL_GUI_CONCRETEUI_H
