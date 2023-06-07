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



        // Getters & setters
        /// Get current scooter
        /// \param identifier
        void getCurrentScooter(string identifier) override;
        /// Set current scooter
        /// \param scooter
        void setCurrentScooter(Scooter scooter) override;

        // ------------------------
        // ISubject
        /// TRy log as manager
        /// \param user
        /// \param pass
        void tryToLogAsManager(string user, string pass) override;
        /// Log in as user
        /// \param user
        /// \param pass
        void tryToLogAsUser(string user, string pass) override;
        /// Crate user account
        /// \param user
        /// \param pass
        void createUserAccount(string user, string pass) override;

        /// Request scooter
        /// \param identifier
        void requestScooter (string identifier) override;

        /// Create, update, delete
        /// \param operation
        /// \param scooter
        void callCUD(Operations operation, const Scooter &scooter) override;

        /// Reserve, Update, Print
        /// \param operation
        /// \param scooter
        /// \param user
        void callRUP(Operations operation, const Scooter &scooter, string user) override;

        /// Get all user scooters
        /// \param userName
        void callVectorAllScootersOfUser(string userName) override;

        /// Sort scooters by attribute
        /// \param operation
        void callVectorSort(Operations operation) override;

        /// Filter by location
        /// \param operations
        /// \param location
        void callFilterLocation(Operations operations, string location) override;

        /// Filter dates
        /// \param operation
        /// \param dates
        void callFilterDates(Operations operation, std::pair<string, string> dates) override;

        /// Call filter km
        /// \param operation
        /// \param km
        void callFilterKm(Operations operation, std::pair<double, double> km) override;
    };

} // ui

#endif //SCOOTER_RENTAL_GUI_CONCRETEUI_H
