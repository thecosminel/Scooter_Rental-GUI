#include "data_validation_functions.h"

namespace utils
{

    bool checkDateFormat(const string& date)
    {
        if (date.length() != 10)
            return false;
        // Check format 'dd.mm.yyyy'
        if (date.at(2) != '.' || date.at(5) != '.' )
            return false;
        // Get day, month, year
        int day, month, year;
        sscanf(date.c_str() ,"%d.%d.%d", &day, &month, &year); //NOLINT
        if (day < 1 || day > 31)
            return false;
        if (month < 1 || month > 12)
            return false;
        if (year < 1000 || year > 9999)
            return false;
        // Check day exceptions
        if (month == 2 && day > 29)
            return false;
        if (month == 2 && day == 29 && (year % 4 != 0))
            return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
            return false;
        return true;
    }

    bool compareScooterByDate(const Scooter& scooter1, const Scooter& scooter2)
    {
        string date1 = scooter1.getDate();
        if (!checkDateFormat(date1))
            throw std::invalid_argument("Invalid date in repo! Data corrupted");
        string date2 = scooter2.getDate();
        if (!checkDateFormat(date2))
            throw std::invalid_argument("Invalid date in repo! Data corrupted");
        return compareDates(date1, date2);
    }

    bool compareScooterByModel(const Scooter& scooter1, const Scooter& scooter2)
    {
        string model1 = scooter1.getModel();
        string model2 = scooter2.getModel();
        return compareStringsAlphabetically(model1, model2);
    }

    bool compareScooterByKm(const Scooter& scooter1, const Scooter& scooter2)
    {
        double km1 = scooter1.getKilometers();
        double km2 = scooter2.getKilometers();
        return km1 <= km2;
    }

    bool compareScooterByLocation(const Scooter& scooter1, const Scooter& scooter2)
    {
        string location1 = scooter1.getLocation();
        string location2 = scooter2.getLocation();
        return compareStringsAlphabetically(location1, location2);
    }

    bool compareScooterByStatus(const Scooter& scooter1, const Scooter& scooter2)
    {
        auto status1 = static_cast<int>(scooter1.getStatus());
        auto status2 = static_cast<int>(scooter2.getStatus());
        return status1 <= status2;
    }

    bool checkIdFormat(const string& ID)
    {
        if (ID.length() != 3) {
            return false;
        }

        for (char c : ID) { // NOLINT
            if (!std::isalpha(c)) {
                return false;
            }
        }
        return true;
    }

    bool compareDates(const string& date1, const string& date2)
    {
        //Format dd.mm.yyyy
        if (!checkDateFormat(date1) || !checkDateFormat(date2))
            throw std::invalid_argument("Date format must be dd.mm.yyyy");
        //Compare
        int day1, month1, year1;
        int day2, month2, year2;
        sscanf(date1.c_str() , "%d.%d.%d", &day1, &month1, &year1); //NOLINT
        sscanf(date2.c_str() , "%d.%d.%d", &day2, &month2, &year2); //NOLINT
        if (year1 < year2)
            return true;
        else if (year1 > year2)
            return false;
        if (month1 < month2)
            return true;
        else if (month1> month2)
            return false;
        if (day1 < day2)
            return true;
        else if (day1 >= day2)
            return false;
        return false; // To avoid error
    }

    bool checkAlphanumericString(const string& str)
    {
        for(char c : str) // NOLINT
        {
            if (!isalnum(c))
            {
                return false;
            }
        }
        return true;
    }

    bool compareStringsAlphabetically(string name1, string name2)
    {
        // Convert strings to lowercase
        for (char& c : name1)
        {
            c = tolower(c); //NOLINT
        }
        for (char& c : name2)
        {
            c = tolower(c); //NOLINT
        }
        if (name1 <= name2)
        {
            return true;
        }
        return false;
    }

    string generateRandomID() {
        std::random_device rd;
        std::mt19937 gen(rd());

        // Possible characters for the ID
        const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

        std::uniform_int_distribution<> dis(0, characters.size() - 1); // NOLINT

        std::string id;
        for (int i = 0; i < 3; ++i)
        {
            id += characters[dis(gen)];
        }

        return id;
    }

    string generateAccessKey()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        // Possible characters for the ID
        const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=;:'<>,./?~`{}[]";

        std::uniform_int_distribution<> dis(0, characters.size() - 1); // NOLINT

        std::string accessKey;
        for (int i = 0; i < 25; ++i)
        {
            accessKey += characters[dis(gen)];
        }

        return accessKey;
    }
}