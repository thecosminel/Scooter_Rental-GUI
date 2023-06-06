#ifndef SCOOTER_RENTAL_GUI_CRUDREPOSITORY_H
#define SCOOTER_RENTAL_GUI_CRUDREPOSITORY_H

#include <vector>

#include "../Domain/Scooter.h"
using namespace scooter;

using std::vector, std::string, std::pair;

namespace repository
{
    class CrudRepository{
    protected:
        vector<Scooter> scooters;
        vector<pair<string, string>> managerAccounts;
        vector<pair<string, string>> userAccounts;

    public:
        /// Default constructor
        CrudRepository() = default;

        /// Default copy constructor
        /// \param repository
        CrudRepository(CrudRepository &repository) = default;

        /// Default assigment operator constructor
        /// \param other
        /// \return
        CrudRepository &operator=(const CrudRepository &other);

        /// Default destructor
        ~CrudRepository() = default;

        // -----------------------------------------------
        // CRUD
        /// Adds an electric scooter to the repository
        /// \param scooter
        virtual void addScooter(const Scooter& scooter) = 0;

        /// Deletes an electric scooter from the repository
        /// \param scooter
        virtual void deleteScooter(const Scooter& scooter) = 0;

        /// Updates an existing electric oldScooter in the repository
        /// \param oldScooter
        /// \param updatedScooter
        virtual void updateScooterInfo(const Scooter& updatedScooter) = 0;

        /// Gets all the electric scooters in the repository
        /// \return
        virtual vector<Scooter> getAllScootersFromRepo() = 0;

        // -----------------------------------------------
        // Access
        /// Check manager acc
        /// \param user
        /// \param pass
        /// \return
        virtual bool checkManagerCredentials(string user, string pass) = 0;

        /// Check user acc
        /// \param user
        /// \param pass
        /// \return
        virtual bool checkUserCredentials(string user, string pass) = 0;

        /// Create user acc
        /// \param user
        /// \param pass
        virtual void createUserAccount(string user, string pass) = 0;

        // -----------------------------------------------
        // Other methods
        /// Gets all scooters with matching location from repo
        /// \param location
        /// \return all matching scooters
        virtual vector<Scooter> getAllScootersByLocation (string location) = 0;

        /// Gets all scooters with km between two given values
        /// \param kmMin
        /// \param kmMax
        /// \return matching scooters
        virtual vector<Scooter> getAllScootersByKmBetweenTwoValues (double kmMin, double kmMax) = 0;

        /// Gets all scooters with dates between two given values
        /// \param dateMin
        /// \param dateMax
        /// \return matching scooters
        virtual vector<Scooter> getAllScootersByAgeBetweenTwoDates (string dateMin, string dateMax) = 0;

        /// Gets all parked scooters (they can be reserved
        /// \return parked scooters
        virtual vector<Scooter> getAllParkedScooters() = 0;

        /// Gets scooters from repo with given ID
        /// \param id
        /// \return scooters with given id
        virtual Scooter getScooterById (string id) = 0;

        /// Gets all scooters reserved by an user
        /// \param userName
        /// \return matching scooters
        virtual vector<Scooter> getAllScootersOfAnUser (string userName) = 0;

        /// Gets all identifiers
        /// \return
        virtual vector<string> getAllIdentifiers() = 0;


        // User operations
        /// Reserve scooter
        /// \param scooter
        /// \param user
        virtual void reserveScooter(Scooter scooter, string user) = 0;

        /// Use scooter
        /// \param scooter
        /// \param user
        virtual void useScooter(Scooter scooter, string user) = 0;

        /// Park scooter
        /// \param scooter
        /// \param user
        virtual void parkScooter(Scooter scooter, string user) = 0;
    };
}


#endif //SCOOTER_RENTAL_GUI_CRUDREPOSITORY_H
