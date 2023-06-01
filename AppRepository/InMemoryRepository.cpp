#include "InMemoryRepository.h"

namespace repository
{

    // Constructors & destructors
    repository::InMemoryRepository::InMemoryRepository(const string& fileName)
    {
        dataFileName = fileName;
        loadFromFile();
    }

    InMemoryRepository &repository::InMemoryRepository::operator=(const repository::InMemoryRepository &other) {
        if (this == &other)
        {
            return *this;
        }

        // Perform deep copy of the Scooters vector
        scooters = other.scooters;

        return *this;
    }

    // CRUD
    void InMemoryRepository::addScooter(const Scooter &scooter)
    {
        int index = 0;
        while (index < scooters.size() && compareNamesAlphabetically(scooters[index].getIdentifier(), scooter.getIdentifier()))
        {
            index++;
        }
        if (index == scooters.size())
            scooters.push_back(scooter);
        else
        {
            scooters.insert(scooters.begin() + index, scooter);
        }
        notify("Scooter added!");
    }

    void InMemoryRepository::deleteScooter(const Scooter &scooter)
    {
        //iterator to find the 'matching scooter' object in the 'scooters' vector
        auto it = scooters.begin();
        while (it != scooters.end())
        {
            if ((*it).checkIfSameIdentifier(scooter))
            {
                scooters.erase(it);
                notify("Scooter deleted!");
                return;
            }
            it++;
        }
        notify("No scooter deleted! Invalid ID");
    }

    void InMemoryRepository::updateScooterInfo(const Scooter &updatedScooter)
    {
        // Searches the oldScooter in the repository based on its identifier
        //iterator to find 'oldScooter' object in the 'electricScooters' vector
        auto it = scooters.begin();
        while (it != scooters.end() && !(*it).checkIfSameIdentifier(updatedScooter))
        {
            it++;
        }
        if (it != scooters.end())
        {
            //update the attributes of the oldScooter with the new values
            (*it).setModel(updatedScooter.getModel());
            (*it).setDate(updatedScooter.getDate());
            (*it).setKilometers(updatedScooter.getKilometers());
            (*it).setLocation(updatedScooter.getLocation());
            (*it).setStatus(updatedScooter.getStatus());
        }
    }

    vector<Scooter> InMemoryRepository::getAllScootersFromRepo()
    {
        auto result = std::vector<Scooter>();
        for (const auto& scooter : scooters)
            result.push_back(scooter);
        return result;
    }



    // -----------------------------------------------
    // Override methods
    vector<Scooter> InMemoryRepository::getAllScootersByLocation(string location)
    {
        auto result = vector<Scooter>();
        for (const Scooter& scooter : scooters)
        {
            for (auto &c : location)
                c = tolower(c); //NOLINT
            string currentLocation = scooter.getLocation();
            for (auto &c : currentLocation)
                c = tolower(c); //NOLINT
            if (currentLocation.find(location) != std::string::npos)
            {
                result.push_back(scooter);
            }
        }
        if (result.empty())
        {
            notify("No scooters with matching location");
        }
        return result;
    }

    vector<Scooter> InMemoryRepository::getAllScootersByKmBetweenTwoValues(double kmMin, double kmMax)
    {
        auto result = vector<Scooter>();
        for (const Scooter& scooter : scooters)
        {
            double km = scooter.getKilometers();
            if ((kmMin == -1 || km >= kmMin) && (kmMax == -1 || km <= kmMax))
            {
                result.push_back(scooter);
            }
        }
        return result;
    }

    vector<Scooter> InMemoryRepository::getAllScootersByAgeBetweenTwoDates(string dateMin, string dateMax)
    {
        auto result = vector<Scooter>();
        for (const Scooter& scooter : scooters)
        {
            string date = scooter.getDate();
            if (compareDates(dateMin, date) && compareDates(date, dateMax))
            {
                result.push_back(scooter);
            }
        }
        if (result.empty())
        {
            notify("No scooters with matching manufacturing dates!");
        }
        return result;
    }

    vector<Scooter> InMemoryRepository::getAllParkedScooters()
    {
        auto result = vector<Scooter>();
        for (const Scooter& scooter : scooters)
        {
            if (scooter.getStatus() == ScooterStatus::PARKED)
            {
                result.push_back(scooter);
            }
        }
        return result;
    }

    Scooter InMemoryRepository::getScooterById(string id)
    {
        for (const Scooter& scooter : scooters)
        {
            if (scooter.getIdentifier() == id)
            {
                return scooter;
            }
        }
        return {};
    }


    // -----------------------------------------------
    // New methods
    void InMemoryRepository::loadFromFile()
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
                ss >> status;

                auto scooterStatus = static_cast<ScooterStatus>(status);
                Scooter scooter(identifier, model, date, kilometers, location, scooterStatus);
                scooters.push_back(scooter);
            }
            file.close();
        }
    }

    vector<Scooter> InMemoryRepository::getAllScootersReservedByAnUser(string userName)
    {
        //TODO - Implementation
    }

    vector<string> InMemoryRepository::getAllIdentifiers()
    {
        vector<string> identifiers;
        for (const auto& scooter : scooters)
        {
            identifiers.push_back(scooter.getIdentifier());
        }
        return identifiers;
    }


}