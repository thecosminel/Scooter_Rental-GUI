#ifndef SCOOTER_RENTAL_GUI_INMEMORYREPOSITORY_H
#define SCOOTER_RENTAL_GUI_INMEMORYREPOSITORY_H

#include "CrudRepository.h"
#include "ISubject.h"
#include "../Utils/data_validation_functions.h"

#include <vector>
#include <sstream>
#include <fstream>

using repository::CrudRepository, repository::ISubject;
using utils::compareDates, utils::checkDateFormat, utils::compareStringsAlphabetically;
using std::ifstream;

namespace repository
{

    class InMemoryRepository : public CrudRepository, public ISubject{
    private:

        /// Load from memory
        void loadScootersFromMemory();

        /// Load acc from memory
        void loadAccountsFromMemory();

    protected:
        string accountsFileName;

    public:
        // Constructors & destructors
        /// Constructor
        explicit InMemoryRepository();

        explicit InMemoryRepository(const string& accountsFileName);

        /// Default copy constructor
        InMemoryRepository(InMemoryRepository &repository) = default;

        /// Assigment operator constructor
        /// \param other
        /// \return copy of InMemoryRepository
        InMemoryRepository& operator=(const InMemoryRepository& other);

        /// Default destructor
        ~InMemoryRepository() = default;

        // -----------------------------------------------
        // CRUD
        /// Adds an electric scooter to the repository
        /// \param scooter
        void addScooter(const Scooter& scooter) override;

        /// Removes an electric scooter from the repository
        /// \param scooter
        void deleteScooter(const Scooter& scooter) override;

        /// Updates an existing electric oldScooter in the repository
        /// \param oldScooter
        void updateScooterInfo(const Scooter& updatedScooter) override;

        /// Gets all the electric scooters in the repository
        /// \return
        vector<Scooter> getAllScootersFromRepo() override;

        // -----------------------------------------------
        // Access
        /// Check manager
        /// \param user
        /// \param pass
        /// \return
        bool checkManagerCredentials(string user, string pass) override;

        /// Check user
        /// \param user
        /// \param pass
        /// \return
        bool checkUserCredentials(string user, string pass) override;

        /// Create user acc
        /// \param user
        /// \param pass
        void createUserAccount(string user, string pass) override;

        // -----------------------------------------------
        // Override methods
        /// Gets all scooters with matching location from repo
        /// \param location
        /// \return all matching scooters
        vector<Scooter> getAllScootersByLocation (string location) override;

        /// Gets all scooters with km between two given values
        /// \param kmMin
        /// \param kmMax
        /// \return matching scooters
        vector<Scooter> getAllScootersByKmBetweenTwoValues (double kmMin, double kmMax) override;

        /// Gets all scooters with dates between two given values
        /// \param dateMin
        /// \param dateMax
        /// \return matching scooters
        vector<Scooter> getAllScootersByAgeBetweenTwoDates (string dateMin, string dateMax) override;

        /// Gets all parked scooters (they can be reserved
        /// \return parked scooters
        vector<Scooter> getAllParkedScooters() override;

        /// Gets scooters from repo with given ID
        /// \param id
        /// \return scooters with given id
        Scooter getScooterById (string id) override;

        /// Gets all scooters reserved by a user
        /// \param userName
        /// \return matching scooters
        vector<Scooter> getAllScootersOfAnUser (string userName) override;

        /// Gets all identifiers in repo
        vector<string> getAllIdentifiers() override;


        // User operations
        /// Reserve scooter
        /// \param scooter
        /// \param user
        void reserveScooter(Scooter scooter, string user) override;

        /// User scooter
        /// \param scooter
        /// \param user
        void useScooter(Scooter scooter, string user) override;

        /// Park scooter
        /// \param scooter
        /// \param user
        void parkScooter(Scooter scooter, string user) override;
    };

}

#endif //SCOOTER_RENTAL_GUI_INMEMORYREPOSITORY_H
