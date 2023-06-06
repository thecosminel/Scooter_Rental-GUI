#ifndef SCOOTER_RENTAL_GUI_IOBSERVER_H
#define SCOOTER_RENTAL_GUI_IOBSERVER_H

#include "../Domain/Scooter.h"

#include <string>

using scooter::Scooter;
using std::string;

#include <iostream>
using std::cout;

namespace controller {

    enum Operations{
        ADD,
        REMOVE,
        UPDATE,
        RESERVE,
        USE,
        PARK,
        SortedId,
        SortedDate,
        SortedModel,
        SortedKm,
        SortedLocation,
        SortedStatus,
        FilteredParked,
        FilteredLocation,
        FilteredDates,
        FilterKm
    };

    class IObserver {
    public:
        IObserver() = default;

        /// Log in as manager
        virtual void logInAsManager(string user, string pass) = 0;

        /// Log in as user
        virtual void logInAsUser(string user, string pass) = 0;

        /// Create user acc
        virtual void createUserAccount(string user, string pass) = 0;

        /// Update alert
        /// \param data
        virtual void update(const string& data) = 0;

        /// Get scooter by id
        /// \param identifier
        virtual void scooterSetCurrent(string identifier) = 0;

        /// Create, Update, Remove scooter
        virtual void scooterCUD(Operations operation, const Scooter& scooter) = 0;

        /// Reserve, Use, Park
        /// \param operation
        /// \param scooter
        /// \param user
        virtual void scooterRUP(Operations operation , const Scooter& scooter, string user) = 0;

        /// Display all scooters of user
        virtual void displayAllScootersOfAnUser(string user) = 0;

        /// Sort operations
        /// \param operation
        virtual void scooterVectorSorted(Operations operation) = 0;

        /// Filter loc
        /// \param operation
        /// \param location
        virtual void scooterVectorFilterLocation(Operations operation, string location) = 0;

        /// Filter dates
        virtual void scooterVectorFilterDates(Operations operation, std::pair<string, string> dates) = 0;

        /// Filter km
        /// \param operation
        /// \param km
        virtual void scooterVectorFilterKm(Operations operation, std::pair<double, double> km) = 0;
    };

}

#endif //SCOOTER_RENTAL_GUI_IOBSERVER_H
