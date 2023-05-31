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
}