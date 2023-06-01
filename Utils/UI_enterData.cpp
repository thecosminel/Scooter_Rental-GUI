#include "UI_enterData.h"

namespace utils
{
    void pressEnterToContinue()
    {
        std::cout << std::endl;
        #ifdef _WIN64
                system("pause");
        #else
                system("read -p 'Press any key to continue...' -n1 -s");
        #endif
    }

    // Login
    string enterUserName()
    {
        string userName;
        cout << endl;
        cout << "Enter user name (must be alphanumeric): ";
        cin >> userName;
        while (!checkAlphanumericString(userName))
        {
            cout << endl << "Please enter an alphanumeric ID: ";
            cin >> userName;
        }
        return userName;
    }

    string enterPassword()
    {
        string password;
        cout << endl;
        cout << "Enter password: ";
        cin >> password;
        return password;
    }


    // Scooter attributes
    string enterModel()
    {
        string model;
        cout << endl;
        cout << "Enter scooter model: ";
        cin >> model;
        return model;
    }

    string enterManufacturingDate()
    {
        string  manufacturingDate;
        cout << endl;
        cout << "Enter manufacturing date: ";
        cin >> manufacturingDate;
        while (!checkDateFormat(manufacturingDate))
        {
            cout << endl << "Please enter a valid manufacturing date:";
            cin >> manufacturingDate;
        }
        return manufacturingDate;
    }

    double enterKm()
    {
        double km;
        cout << endl;
        cout << "Enter km: ";
        cin >> km;
        return km;
    }

    string enterLocation()
    {
        string location;
        cout << endl;
        cout << "Enter location: ";
        cin >> location;
        return location;
    }

    ScooterStatus enterStatus()
    {
        cout << endl;
        cout << "Select status: 1.PARKED / 2.RESERVED / 3.IN_USE / 4.MAINTENANCE / 5.OUT_OF_SERVICE / 6.UNKNOWN)";
        char choice;
        cout << "My choice: "; cin >> choice;
        switch (choice)
        {
            case '1':
                return PARKED;
            case '2':
                return RESERVED;
            case '3':
                return IN_USE;
            case '4':
                return MAINTENANCE;
            case '5':
                return OUT_OF_SERVICE;
            case '6':
            default:
                return UNKNOWN;
        }
    }

} // utils