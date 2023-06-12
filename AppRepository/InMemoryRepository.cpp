#include "InMemoryRepository.h"

namespace repository
{

    // Constructors & destructors
    repository::InMemoryRepository::InMemoryRepository()
    {
        accountsFileName = "Database/Accounts/accounts.csv";
        loadAccountsFromMemory();
        loadScootersFromMemory();
    }

    repository::InMemoryRepository::InMemoryRepository(const string& accountsFileName)
    {
        this->accountsFileName =  accountsFileName;
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
        while (index < scooters.size() &&
                compareStringsAlphabetically(scooters[index].getIdentifier(), scooter.getIdentifier()))
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
            (*it).setUser(updatedScooter.getUser());
            notify("Scooter updated!");
        }
        if (it == scooters.end())
        {
            notify("Invalid scooter ID!");
        }
    }

    vector<Scooter> InMemoryRepository::getAllScootersFromRepo()
    {
        auto result = std::vector<Scooter>();
        for (const auto& scooter : scooters)
            result.push_back(scooter);
        if (result.empty())
        {
            notify("Repository empty");
        }
        return result;
    }

    // -----------------------------------------------
    // Access
    bool InMemoryRepository::checkManagerCredentials(string user, string pass)
    {
        for (const auto& account : managerAccounts) //NOLINT
        {
            if (account.first == user && account.second == pass)
                return true;
        }
        return false;
    }

    bool InMemoryRepository::checkUserCredentials(string user, string pass)
    {
        for (const auto& account : userAccounts) //NOLINT
        {
            if (account.first == user && account.second == pass)
                return true;
        }
        return false;
    }

    void InMemoryRepository::createUserAccount(string user, string pass)
    {
        for (const auto& account : userAccounts) //NOLINT
        {
            if (account.first == user && account.second == pass)
            {
                notify("Account already exits!");
                return;
            }
        }
        pair <string, string> newUserAccount;
        newUserAccount.first = user;
        newUserAccount.second = pass;
        userAccounts.push_back(newUserAccount);
        notify("New user account created!");
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
        if (result.empty())
        {
            notify("No scooters with matching km");
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
        throw std::invalid_argument("Invalid identifier");
    }


    // -----------------------------------------------
    // New methods
    void InMemoryRepository::loadScootersFromMemory()
    {
        // Add 10 scooters stored in memory
        Scooter scooter1("aaa", "Ola-S1", "03.06.2022", 55500.5, "Zamca", scooter::UNKNOWN);
        Scooter scooter2("aab", "Honda-Navi", "11.02.2019", 1, "Selimbar", scooter::OUT_OF_SERVICE);
        Scooter scooter3("aac", "Yamaha 1", "19.09.2030", 5.5, "Salcea", scooter::UNKNOWN);
        Scooter scooter4("aad", "Yamaha 2", "03.10.2023", 300.13, "Medias", scooter::PARKED);
        Scooter scooter5("afc", "Emv-Scoot", "09.11.2019", 30, "Sibiu", scooter::IN_USE);
        Scooter scooter6("ACs", "Swagtron-5", "01.03.2020", 15.2, "Manhattanstur", scooter::PARKED);
        Scooter scooter7("afv", "E-Twow-GT", "08.05.2020", 1002.23, "Itcani", scooter::PARKED);
        Scooter scooter8("gjd", "InMotion-S1", "14.11.2021", 87.323, "Pakistan", scooter::MAINTENANCE);
        Scooter scooter9("fgF", "Apollo-City", "12.07.2022", 44.444, "Avrig", scooter::MAINTENANCE);
        Scooter scooter10("OkK", "Varla-One", "23.04.2023", 290.23, "Turnisor", scooter::OUT_OF_SERVICE);
        scooters.push_back(scooter1);
        scooters.push_back(scooter2);
        scooters.push_back(scooter3);
        scooters.push_back(scooter4);
        scooters.push_back(scooter5);
        scooters.push_back(scooter6);
        scooters.push_back(scooter7);
        scooters.push_back(scooter8);
        scooters.push_back(scooter9);
        scooters.push_back(scooter10);
    }

    void InMemoryRepository::loadAccountsFromMemory()
    {
        pair<string, string> manager1{"Tud", "bmw"};
        pair<string, string> manager2{"1", ""};
        pair<string, string> user1{"geo", "bos"};
        pair<string, string> user2{"ana", "mere"};
        managerAccounts.push_back(manager1);
        managerAccounts.push_back(manager2);
        userAccounts.push_back(user1);
        userAccounts.push_back(user2);
    }

    vector<Scooter> InMemoryRepository::getAllScootersOfAnUser(string userName)
    {
        vector<Scooter> result;
        for (const Scooter& scooter : scooters)
        {
            if (scooter.getUser() == userName)
            {
                ScooterStatus status = scooter.getStatus();
                if (status == scooter::RESERVED || status == scooter::IN_USE)
                {
                    result.push_back(scooter);
                }
            }
        }
        if (result.empty())
        {
            notify("User doesn't have any scooters!");
        }
        return result;
    }

    vector<string> InMemoryRepository::getAllIdentifiers()
    {
        vector<string> identifiers;
        identifiers.reserve(scooters.size());
        for (const auto& scooter : scooters)
        {
            identifiers.push_back(scooter.getIdentifier());
        }
        return identifiers;
    }

    void InMemoryRepository::reserveScooter(Scooter scooter, string user)
    {
        string identifier = scooter.getIdentifier();
        Scooter matchingScooter = getScooterById(identifier);
        if (matchingScooter.getStatus() != scooter::PARKED)
            throw std::invalid_argument("Scooter not reserved as it is not available");
        scooter.setUser(user);
        scooter.setStatus(scooter::RESERVED);
        updateScooterInfo(scooter);
    }

    void InMemoryRepository::useScooter(Scooter scooter, string user)
    {
        string identifier = scooter.getIdentifier();
        Scooter matchingScooter = getScooterById(identifier);
        if (matchingScooter.getStatus() != scooter::RESERVED)
            throw std::invalid_argument("Scooter not reserved as it is not reserved");
        if (matchingScooter.getUser() != user)
            throw std::invalid_argument("Scooters belongs to other user");
        scooter.setUser(user);
        scooter.setStatus(scooter::IN_USE);
        updateScooterInfo(scooter);
    }

    void InMemoryRepository::parkScooter(Scooter scooter, string user)
    {
        string identifier = scooter.getIdentifier();
        Scooter matchingScooter = getScooterById(identifier);
        if (matchingScooter.getStatus() != scooter::IN_USE)
            throw std::invalid_argument("Scooter not reserved as it is not in use");
        if (matchingScooter.getUser() != user)
            throw std::invalid_argument("Scooters belongs to other user");
        scooter.setUser(user);
        scooter.setStatus(scooter::PARKED);
        updateScooterInfo(scooter);
    }




}