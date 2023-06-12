#include "CsvFileRepository.h"

namespace repository
{
    // Constructors & destructors
    CsvFileRepository::CsvFileRepository(const string &fileName, const string& accountsFileName) : InMemoryRepository(accountsFileName)
    {
        this->dataFileName = fileName;
        loadFromFile();
        loadAccountsFromFile();
    }

    CsvFileRepository::~CsvFileRepository()
    {
        saveToFile();
        saveAccountsToFile();
    }

    CsvFileRepository &CsvFileRepository::operator=(const CsvFileRepository &other){
        if (this == &other)
        {
            return *this;
        }
        // Perform deep copy of the Scooters vector
        scooters = other.scooters;
        return *this;
    }


    // Other
    void CsvFileRepository::loadFromFile()
    {
        ifstream file(dataFileName);
        std::string line;
        std::getline(file, line);
        if (file.is_open())
        {

            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string element;

                std::string identifier;
                std::string model;
                std::string date;
                double kilometers;
                std::string location;
                int status;
                std::string user;

                // Read each element separated by commas
                std::getline(ss, identifier, ',');
                std::getline(ss, model, ',');
                std::getline(ss, date, ',');
                if (!checkDateFormat(date))
                {
                    throw std::invalid_argument("File contains invalid dates!");
                }
                ss >> kilometers;
                ss.ignore(); // Ignore the comma after 'kilometers'
                std::getline(ss, location, ',');
                std::getline(ss, user, ',');
                ss >> status;

                auto scooterStatus = static_cast<ScooterStatus>(status);
                Scooter scooter(identifier, model, date, kilometers, location, scooterStatus);
                scooter.setUser(user);
                scooters.push_back(scooter);
            }
            file.close();
        }
        else
        {
            throw std::invalid_argument("Invalid file");
        }
    }

    void CsvFileRepository::saveToFile()
    {
        std::ofstream file(dataFileName);
        if (file.is_open())
        {
            file << "Identifier" << ',' << "Model" << ',' << "ManufacturingDate" << ',';
            file << "Km" << ',' << "Location" << ',' << "User" << ',' << "Status" << endl;
            for (const auto& scooter : scooters) {
                file << scooter.getIdentifier() << ',';
                file << scooter.getModel() << ',';
                file << scooter.getDate() << ',';
                file << scooter.getKilometers() << ',';
                file << scooter.getLocation() << ',';
                file << scooter.getUser() << ',';
                file << static_cast<int>(scooter.getStatus()) << std::endl;
            }
            file.close();
        }
    }

    void CsvFileRepository::loadAccountsFromFile()
    {
        ifstream file(accountsFileName);
        std::string line;
        std::getline(file, line);
        if (file.is_open())
        {
            while (std::getline(file, line))
            {
                std::stringstream ss(line);
                string user;
                string password;
                string userType;
                std::getline(ss, user, ',');
                std::getline(ss, password, ',');
                std::getline(ss, userType, ',');
                pair<string, string> userPass;
                userPass.first = user;
                userPass.second = password;
                if (userType == "manager")
                    managerAccounts.push_back(userPass);
                else
                    userAccounts.push_back(userPass);
            }
            file.close();
        }
    }

    void CsvFileRepository::saveAccountsToFile()
    {
        std::ofstream file(accountsFileName);
        if (file.is_open())
        {
            file << userAccounts.size() + managerAccounts.size() << std::endl;
            for (const auto& accounts : managerAccounts)
            {
                file << accounts.first << ',';
                file << accounts.second << ',';
                file << "manager" << ',';
                file << endl;
            }
            for (const auto& accounts : userAccounts)
            {
                file << accounts.first << ',';
                file << accounts.second << ',';
                file << "user" << ',';
                file << endl;
            }
            file.close();
        }
    }

}