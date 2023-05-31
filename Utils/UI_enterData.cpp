#include "UI_enterData.h"

namespace utils
{
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

    void pressEnterToContinue()
    {
        std::cout << std::endl;
        #ifdef _WIN64
                system("pause");
        #else
                system("read -p 'Press any key to continue...' -n1 -s");
        #endif
    }

} // utils