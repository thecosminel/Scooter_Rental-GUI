#ifndef SCOOTER_RENTAL_GUI_CSVREPOSITORY_H
#define SCOOTER_RENTAL_GUI_CSVREPOSITORY_H

#include "InMemoryRepository.h"

#include <fstream>

using std::ifstream, std::endl;

namespace repository {

    class CsvFileRepository : public InMemoryRepository{
    private:
        string dataFileName;

        /// Load csv
        void loadFromFile();
        /// Save to csv
        void saveToFile();
        /// Load  accounts from csv
        void loadAccountsFromFile();
        /// Save accounts to csv
        void saveAccountsToFile();

    public:
        /// Default constructor
        explicit CsvFileRepository(const string& fileName = "../Database/data.csv", const string& accountsFileName = "Database/Accounts/accounts.csv");

        /// Default copy constructor
        CsvFileRepository(CsvFileRepository &repository) = default;

        /// Assigment operator
        CsvFileRepository& operator=(const CsvFileRepository& other);

        /// Destructor
        ~CsvFileRepository();
    };

} // repository

#endif //SCOOTER_RENTAL_GUI_CSVREPOSITORY_H
