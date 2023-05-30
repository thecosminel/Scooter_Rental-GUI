#ifndef SCOOTER_RENTAL_GUI_ABSTRACTCONTROLLER_H
#define SCOOTER_RENTAL_GUI_ABSTRACTCONTROLLER_H

#include "../AppRepository/InMemoryRepository.h"
#include "../Domain/Scooter.h"
#include "IObserver.h"

#include "memory"

using repository::CrudRepository;
using namespace scooter;
using std::shared_ptr;

namespace controller {

    class AbstractController : public IObserver{
    private:
        shared_ptr<CrudRepository> repo;

    public:
        // ----------------------------
        // Constructors & destructors
        /// Constructor
        /// \param repo
        explicit AbstractController(shared_ptr<CrudRepository> repo);

        ///Copy-constructor
        AbstractController(AbstractController& controller) = default;

        ///Assignment operator
        AbstractController& operator=(const AbstractController& repository) = default;

        ///Destructor
        ~AbstractController() = default;

        // ----------------------------
        // Create, Update, Delete
        /// Adds scooter to repo
        /// \param newScooter
        virtual void addScooterToRepo(Scooter newScooter) = 0;

        /// Removes scooter from repo
        /// \param removedScooter
        virtual void deleteScooterFomRepo(Scooter removedScooter) = 0;

        /// Update scooter in repo
        /// \param updatedScooter
        virtual void updateScooterFromRepo(Scooter updatedScooter) = 0;

        /// Reserve scooter
        /// \param ID scooter ID
        /// \return true if the scooter was successfully reserved, false otherwise
        virtual void reserveScooter(const string& ID, const string& username) = 0;

        // ----------------------------
        // Read - filter
        /// Filter scooters by location
        /// \param location string after which to search scooter
        /// \return shared pointer to a vector of scooters that contain the given location string
        virtual void filterScootersByLocation(string location) = 0;

        /// Filter scooters that have Km in between two specified values
        /// \param kmMin minimum value to filter
        /// \param kmMax maximum value to filter
        /// \return shared pointer to a vector of scooters that have a km value in between the given values
        virtual void filterScootersByKmBetweenTwoValues(double kmMin, double kmMax) = 0;

        /// Filter scooters that have been manufactured in between the given dates
        /// \param dateMin minimum date to filter
        /// \param dateMax maximum date to filter
        /// \return shared pointer to a vector of scooters that have been manufactured in between the given dates
        virtual void filterScootersByAgeBetweenTwoDates(string dateMin, string dateMax) = 0;

        /// Filter parked scooters
        /// \return shared pointer to a vector of scooters that are currently parked
        virtual void filterParkedScooters() = 0;

        // ----------------------------
        // Read - sort
        /// Sort scooters by ID lexicographically
        /// \return shared pointer to a vector of scooters that have been sorted by their ID
        virtual void sortScootersByID() = 0;

        /// Sort scooters by manufacturing date ascending
        /// \return shared pointer to a vector of scooters that have been sorted by their age
        virtual void sortScootersByManufacturingDate() = 0;
    };

} // controller

#endif //SCOOTER_RENTAL_GUI_ABSTRACTCONTROLLER_H
