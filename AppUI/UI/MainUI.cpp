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
        cout << "\n\n\nManager interface -->" << endl;
//        logIn();
        char choice;
        do
        {
            pressEnterToContinue();
            cout << "Choose option: " << endl;
            cout << "  1. Add new scooter" << endl;
            cout << "  2. Delete existing scooter" << endl;
            cout << "  3. Modify existing scooter" << endl;
            cout << "  4. Search scooter by location" << endl;
            cout << "  5. Display scooters with km between two values" << endl;
            cout << "  6. Display scooters manufactured between two dates" << endl;
            cout << "  7. Display all scooters sorted ascending by manufacturing date" << endl;
            cout << "  8. Display all scooters sorted ascending by ID" << endl;
            cout << "  R. Return to main ui" << endl;
            cout << "  X. Close app" << endl;
            cin >> choice;
            cout << endl;

            switch (choice)
            {
                case '1':
                    cout << "Add new scooter: ";
                    addNewScooter();
                    break;
                case '2':
                    cout << "Delete existing scooter: ";
    //                deleteExistingScooter();
                    break;
                case '3':
                    cout << "Modify existing scooter: ";
    //                modifyExistingScooter()

                    break;
                case '4':
                    cout << "Search scooter by location: ";
    //                searchScooterByLocation();
                    break;
                case '5':
                    cout << "Display scooters with km less than:  ";
    //                displayScootersFilteredByKm();
                    break;
                case '6':
                    cout << "Display scooters newer than date:  ";
    //                displayScootersFilteredByAge();
                    break;
                case '7':
                    cout << "Display all scooters sorted ascending by age: ";
                    displayAllScootersSortedByAge();
                    break;
                case '8':
                    cout << "Display all scooters sorted ascending by ID: ";
                    displayAllScootersSortedByID();
                    break;
                case 'R':
                case 'r':
                    cout << "+++ Closing app +++ ";
                    return true;
                case 'X':
                case 'x':
                    cout << "+++ Closing app +++ ";
                    return false;
                default:
                    cout << "Not an option...";
                    break;
        }
    }
    while (choice);
        return false;
    }

    bool MainUI::runUser()
    {
        logIn();
        return false;
    }

    void MainUI::logIn()
    {
        cout << "You have to log in..." << endl;
        this->user = enterUserName();
        this->password = enterPassword();
    }


    // ------------------------
    // Manager & User methods
    void MainUI::displayAllScootersSortedByAge()
    {

    }

    void MainUI::displayAllScootersSortedByID()
    {

    }

    void MainUI::addNewScooter()
    {
        cout << endl << "You have selected to add a new Scooter";
//        string model = enterModel();
//        string identifier = "NIL";
//        string manufacturingDate = enterManufacturingDate();
//        double km = enterKm();
//        string location = enterLocation();
//        ScooterStatus status = enterStatus();
        string model = "Yamaha";
        string identifier = "NIL";
        string manufacturingDate = "10.10.2020";
        double km = 12.34;
        string location = "Bosanci";
        ScooterStatus status = PARKED;
        Scooter newScooter(identifier, model, manufacturingDate, km, location, status);
        ConcreteUI::callCUD(controller::ADD,newScooter);
    }

} // ui