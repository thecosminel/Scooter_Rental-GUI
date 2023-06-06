#ifndef SCOOTER_RENTAL_GUI_CONCRETECONTROLLER_H
#define SCOOTER_RENTAL_GUI_CONCRETECONTROLLER_H

#include "IObserver.h"
#include "AbstractController.h"
#include "../Utils/data_validation_functions.h"

using namespace controller;
using utils::generateRandomID, utils::compareScooterByDate;

namespace controller {

    class ConcreteController  : public AbstractController, public IObserver {
    private:
        string generateNewId();
    public:
        // ----------------------------
        // Constructors & destructors
        /// Constructor
        /// \param repo
        explicit ConcreteController(shared_ptr<CrudRepository> repo, shared_ptr<AbstractUI> ui);

        ///Copy-constructor
        ConcreteController(ConcreteController& controller) = default;

        ///Assignment operator
        ConcreteController& operator=(const ConcreteController& repository) = default;

        ///Destructor
        ~ConcreteController() = default;

        // ----------------------------
        // Create, Update, Delete
        /// Adds scooter to repo
        /// \param newScooter
        void addScooterToRepo(Scooter newScooter) override;

        /// Removes scooter from repo
        /// \param removedScooter
        void deleteScooterFomRepo(Scooter removedScooter) override;

        /// Update scooter in repo
        /// \param updatedScooter
        void updateScooterFromRepo(Scooter updatedScooter) override;

        /// Reserve scooter
        /// \param ID scooter ID
        /// \return true if the scooter was successfully reserved, false otherwise
        void reserveScooter(Scooter scooter, const string& username) override;

        /// Use scooter
        /// \param usedScooter
        /// \param username
        void useScooter(Scooter usedScooter, const string& username) override;

        /// Park scooter
        /// \param toParkScooter
        /// \param username
        void parkScooter(Scooter toParkScooter, const string& username) override;

        // ----------------------------
        // Read - filter
        /// Filter scooters by location
        /// \param location string after which to search scooter
        /// \return shared pointer to a vector of scooters that contain the given location string
        void filterScootersByLocation(string location) override;

        /// Filter scooters that have Km in between two specified values
        /// \param kmMin minimum value to filter
        /// \param kmMax maximum value to filter
        /// \return shared pointer to a vector of scooters that have a km value in between the given values
        void filterScootersByKmBetweenTwoValues(double kmMin, double kmMax) override;

        /// Filter scooters that have been manufactured in between the given dates
        /// \param dateMin minimum date to filter
        /// \param dateMax maximum date to filter
        /// \return shared pointer to a vector of scooters that have been manufactured in between the given dates
        void filterScootersByAgeBetweenTwoDates(string dateMin, string dateMax) override;

        /// Filter parked scooters
        /// \return shared pointer to a vector of scooters that are currently parked
        void filterParkedScooters() override;

        // ----------------------------
        // Read - sort
        /// Sort scooters by ID lexicographically
        /// \return shared pointer to a vector of scooters that have been sorted by their ID
        void sortScootersByID() override;

        /// Sort scooters by manufacturing date ascending
        /// \return shared pointer to a vector of scooters that have been sorted by their age
        void sortScootersByManufacturingDate() override;

        void sortScootersByModel() override;
        void sortScootersByKm() override;
        void sortScootersByLocation() override;
        void sortScootersByStatus() override;

        // ------------------------------
        // IObserver override
        /// Update scooter
        void update(const string &data) override;

        /// Log in manager
        /// \param user
        /// \param pass
        void logInAsManager(string user, string pass) override;

        /// Log in user
        /// \param user
        /// \param pass
        void logInAsUser(string user, string pass) override;

        /// Create user account
        /// \param user
        /// \param pass
        void createUserAccount(string user, string pass) override;

        /// Get scooter by id and save it in UI
        void scooterSetCurrent(string identifier) override;

        /// Create, Update, Remove scooter
        /// \param operation
        /// \param scooter
        void scooterCUD(Operations operation, const Scooter& scooter) override;

        /// Reserve, Use, Park scooter
        /// \param operation
        /// \param scooter
        void scooterRUP(Operations operation , const Scooter& scooter, string user) override;

        /// Print all scooters of user
        /// \param user
        void displayAllScootersOfAnUser(string user) override;

        /// Print all scooters
        void scooterVectorSorted(Operations operation) override;

        /// Filter by location
        /// \param operation
        /// \param location
        void scooterVectorFilterLocation(Operations operation, string location) override;

        /// Filter Filter by date
        /// \param operation
        /// \param dates
        void scooterVectorFilterDates(Operations operation, std::pair<string, string> dates) override;

        /// Filter by km
        /// \param operation
        /// \param km
        void scooterVectorFilterKm(Operations operation, std::pair<double, double> km) override;
    };

} // controller

#endif //SCOOTER_RENTAL_GUI_CONCRETECONTROLLER_H
