#include "MainUI.h"

namespace ui
{
    // Main methods
    void MainUI::run()
    {
        // Select Manager/User
        bool restartMainUi;
        do
        {
            cout << endl << endl;
            cout << "Welcome to our Electric Scooter Rental App!!" << endl;
            cout << "What are you?" << endl;
            cout << " 1. Manager" << endl;
            cout << " 2. User" << endl;
            cout << "I am: ";
            int choice; cin >> choice;
            while (choice != 1 && choice != 2)
            {
                cout << "Choose between 1 or 2" << endl;
                cout << "I am: ";
                cin >> choice;
            }
            if (choice == 1)
                restartMainUi = runManager();
            if (choice == 2)
                restartMainUi = runUser();
        }
        while (restartMainUi);

    }

    bool MainUI::runManager()
    {
        logIn();
    }

    bool MainUI::runUser()
    {
        logIn();
    }

    void MainUI::logIn()
    {
        cout << "You have to log in..." << endl;
        this->user = enterUserName();
        this->password = enterPassword();
    }

} // ui