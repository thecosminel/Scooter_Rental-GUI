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
        cout << "Use following manager account (user: 'Tud'; pass: 'bmw')" << endl;
        logInAsManager();
        char choice;
        do
        {
            pressEnterToContinue();
            cout << "Choose option: " << endl;
            cout << "CUD methods:" << endl;
            cout << "  A. Add new scooter" << endl;
            cout << "  D. Delete existing scooter" << endl;
            cout << "  M. Modify existing scooter" << endl;
            cout << "All scooters sort methods: " << endl;
            cout << "  1. Display all scooters sorted ascending by ID" << endl;
            cout << "  2. Display all scooters sorted ascending by model" << endl;
            cout << "  3. Display all scooters sorted ascending by manufacturing date" << endl;
            cout << "  4. Display all scooters sorted ascending by Km" << endl;
            cout << "  5. Display all scooters sorted ascending by location" << endl;
            cout << "  6. Display all scooters sorted ascending by status" << endl;
            cout << "Search methods: " << endl;
            cout << "  L. Search scooter by location" << endl;
            cout << "  7. Display scooters with km between two values" << endl;
            cout << "  8. Display scooters manufactured between two dates" << endl;
            cout << "  9. Display all parked scooters" << endl;
            cout << "  B. Return to main ui" << endl;
            cout << "  X. Close app" << endl;
            cin >> choice;
            cout << endl;

            switch (choice)
            {
                case 'A':
                case 'a':
                    cout << "Add new scooter: ";
                    addNewScooter();
                    break;
                case 'D':
                case 'd':
                    cout << "Delete existing scooter: ";
                    deleteExistingScooter();
                    break;
                case 'M':
                case 'm':
                    cout << "Modify existing scooter: ";
                    modifyExistingScooter();
                    break;
                // All scooters sort methods
                case '1':
                    cout << "Display all scooters sorted ascending by ID: ";
                    displayAllScootersSortedByID();
                    break;
                case '2':
                    cout << "Display all scooters sorted ascending by model: ";
                    displayAllScootersSortedByModel();
                    break;
                case '3':
                    cout << "Display all scooters sorted ascending by age: ";
                    displayAllScootersSortedByAge();
                    break;
                case '4':
                    cout << "Display all scooters sorted ascending by km: ";
                    displayAllScootersSortedByKm();
                    break;
                case '5':
                    cout << "Display all scooters sorted ascending by location: ";
                    displayAllScootersSortedByLocation();
                    break;
                case '6':
                    cout << "Display all scooters sorted ascending by status: ";
                    displayAllScootersSortedByStatus();
                    break;
                // Search methods
                case 'L':
                case 'l':
                    cout << "Search scooter by location: ";
                    searchScooterByLocation();
                    break;
                case '7':
                    cout << "Display scooters with km between:  ";
                    displayScootersFilteredByKm();
                    break;
                case '8':
                    cout << "Display scooters with manufacturing date between:  ";
                    displayScootersFilteredByDates();
                    break;

                case '9':
                    cout << "Display all parked scooters: ";
                    displayAllParkedScooters();
                    break;
                case 'B':
                case 'b':
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
        cout << "\n\n\nUser interface -->" << endl;
        logInAsUser();
        char choice;
        do
        {
            pressEnterToContinue();
            cout << "Choose option: " << endl;
            cout << "All scooters sort methods: " << endl;
            cout << "  1. Display all scooters sorted ascending by ID" << endl;
            cout << "  2. Display all scooters sorted ascending by model" << endl;
            cout << "  3. Display all scooters sorted ascending by manufacturing date" << endl;
            cout << "  4. Display all scooters sorted ascending by Km" << endl;
            cout << "  5. Display all scooters sorted ascending by location" << endl;
            cout << "  6. Display all scooters sorted ascending by status" << endl;

            cout << "Search methods: " << endl;
            cout << "  L. Search scooter by location" << endl;
            cout << "  7. Display scooters with km between two values" << endl;
            cout << "  8. Display scooters manufactured between two dates" << endl;
            cout << "  9. Display all parked scooters" << endl;

            cout << "  M.  Display all my scooters" << endl;
            cout << "  R.  Reserve scooter" << endl;
            cout << "  U.  Use scooter" << endl;
            cout << "  P. Park scooter" << endl;
            cout << "  B. Return to main ui" << endl;
            cout << "  X. Close app" << endl;
            cin >> choice;
            cout << endl;

            switch (choice)
            {
                // All scooters sort methods
                case '1':
                    cout << "Display all scooters sorted ascending by ID: ";
                    displayAllScootersSortedByID();
                    break;
                case '2':
                    cout << "Display all scooters sorted ascending by model: ";
                    displayAllScootersSortedByModel();
                    break;
                case '3':
                    cout << "Display all scooters sorted ascending by age: ";
                    displayAllScootersSortedByAge();
                    break;
                case '4':
                    cout << "Display all scooters sorted ascending by km: ";
                    displayAllScootersSortedByKm();
                    break;
                case '5':
                    cout << "Display all scooters sorted ascending by location: ";
                    displayAllScootersSortedByLocation();
                    break;
                case '6':
                    cout << "Display all scooters sorted ascending by status: ";
                    displayAllScootersSortedByStatus();
                    break;
                    // Search methods
                case 'L':
                case 'l':
                    cout << "Search scooter by location: ";
                    searchScooterByLocation();
                    break;
                case '7':
                    cout << "Display scooters with km between:  ";
                    displayScootersFilteredByKm();
                    break;
                case '8':
                    cout << "Display scooters with manufacturing date between:  ";
                    displayScootersFilteredByDates();
                    break;

                case '9':
                    cout << "Display all parked scooters: ";
                    displayAllParkedScooters();
                    break;

                // Personal scooters
                case 'M':
                case 'm':
                    cout << "Display all my scooters:" << endl;
                    displayMyScooters();
                    break;
                case 'R':
                case 'r':
                    cout << "Reserve scooter:" << endl;
                    reserveScooter();
                    break;
                case 'U':
                case 'u':
                    cout << "Use scooter:" << endl;
                    useScooter();
                    break;
                case 'p':
                case 'P':
                    cout << "Park scooter:" << endl;
                    parkScooter();
                    break;
                case 'B':
                case 'b':
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

    void MainUI::logInAsManager()
    {
        bool retry = true;
        while (retry)
        {
            cout << "You have to log in..." << endl;
            this->user = enterUserName();
            this->password = enterPassword();
            try {
                ConcreteUI::tryToLogAsManager(user, password);
                retry = false;
            }
            catch (const std::invalid_argument& e)
            {
                cout << "Exception: " << e.what() << endl;
                retry = true;
            }
        }
    }

    void MainUI::logInAsUser()
    {
        bool retry = true;
        while (retry)
        {
            cout << "You have to log in..." << endl;
            this->user = enterUserName();
            this->password = enterPassword();
            try {
                ConcreteUI::tryToLogAsUser(user, password);
                retry = false;
            }
            catch (const std::invalid_argument& e)
            {
                cout << "Exception: " << e.what() << endl << endl;
                cout << "Enter 1 to try again or any key to create new account" << endl;
                char choice;
                cout << "My choice: "; cin >> choice;
                if (choice != '1')
                {
                    this->user = enterUserName();
                    this->password = enterPassword();
                    ConcreteUI::createUserAccount(user, password);
                }
                retry = true;
            }
        }
    }


    // ------------------------
    // Manager & User methods
    void MainUI::displayAllScootersSortedByAge()
    {
        ConcreteUI::callVectorSort(controller::SortedDate);
    }

    void MainUI::displayAllScootersSortedByID()
    {
        ConcreteUI::callVectorSort(controller::SortedId);
    }

    void MainUI::displayAllParkedScooters()
    {
        ConcreteUI::callVectorSort(controller::FilteredParked);
    }

    void MainUI::searchScooterByLocation()
    {
        string location = enterLocation();
        ConcreteUI::callFilterLocation(controller::FilteredLocation, location);
    }

    void MainUI::displayScootersFilteredByDates()
    {
        pair<string, string> dates = enterManufacturingDates();
        ConcreteUI::callFilterDates(controller::FilteredDates, dates);
    }

    void MainUI::displayScootersFilteredByKm()
    {
        pair<double, double> km = enterKmMultiple();
        ConcreteUI::callFilterKm(controller::FilterKm, km);
    }

    void MainUI::addNewScooter()
    {
        cout << endl << "You have selected to add a new Scooter";
        string model = enterModel();
        string identifier = "NIL";
        string manufacturingDate = enterManufacturingDate();
        double km = enterKm();
        string location = enterLocation();
        ScooterStatus status = enterStatus();
        Scooter newScooter(identifier, model, manufacturingDate, km, location, status);
        ConcreteUI::callCUD(controller::ADD,newScooter);
    }

    void MainUI::deleteExistingScooter()
    {
        cout << endl << "You have selected to delete an existing Scooter";
        string identifier = enterID();
        Scooter removedScooter(identifier, "", "10.10.2010", 1, "", UNKNOWN);
        ConcreteUI::callCUD(controller::REMOVE, removedScooter);
    }

    void MainUI::modifyExistingScooter()
    {
        cout << endl << "You have selected to modify an existing Scooter";
        string identifier = enterID();
        try {
            ConcreteUI::getCurrentScooter(identifier);
        }
        catch (const std::logic_error& exception)
        {
            cout << endl << "Error: " << exception.what() << endl;
            return;
        }
        vector<Scooter> scooterInVector;
        Scooter updatedScooter = currentScooter;
        char choice;
        bool done = false;
        do
        {
            scooterInVector.clear();
            scooterInVector.push_back(updatedScooter);
            cout << "Current updated scooter:" << endl;
            ConcreteUI::printScooterContainer(scooterInVector);
            cout << "What do you want to modify: " << endl;
            cout << "  1. Model" << endl;
            cout << "  2. Manufacturing date" << endl;
            cout << "  3. Km" << endl;
            cout << "  4. Location" << endl;
            cout << "  5. Status" << endl;
            cout << "  x. That's all"<< endl;
            cout << "My choice: "; cin >> choice;
            switch (choice)
            {
                case '1':
                {
                    string model = enterModel();
                    updatedScooter.setModel(model);
                    break;
                }

                case '2':
                {
                    string date = enterManufacturingDate();
                    updatedScooter.setDate(date);
                    break;
                }

                case '3':
                {
                    double km = enterKm();
                    updatedScooter.setKilometers(km);
                    break;
                }

                case '4':
                {
                    string location = enterLocation();
                    updatedScooter.setLocation(location);
                    break;
                }
                case '5':
                {
                    ScooterStatus status = enterStatus();
                    updatedScooter.setStatus(status);
                    break;
                }
                case 'x':
                case 'X':
                    done = true;
                    break;
                default:
                    cout << "Not an option!" << endl;
            }
        } while (!done);
        ConcreteUI::callCUD(controller::UPDATE, updatedScooter);
    }

    // -------------------------
    // User UI only
    void MainUI::reserveScooter()
    {
        string identifier = enterID();
        try {
            ConcreteUI::getCurrentScooter(identifier);
        }
        catch (const std::logic_error& exception)
        {
            cout << endl << "Error: " << exception.what() << endl;
            return;
        }
        Scooter scooter = currentScooter;
        try {
            ConcreteUI::callRUP(controller::RESERVE, scooter, user);
        }
        catch (const std::logic_error& exception)
        {
            cout << endl << "Error: " << exception.what() << endl;
            return;
        }
    }

    void MainUI::parkScooter()
    {
        string identifier = enterID();
        try {
            ConcreteUI::getCurrentScooter(identifier);
        }
        catch (const std::logic_error& exception)
        {
            cout << endl << "Error: " << exception.what() << endl;
            return;
        }
        Scooter scooter = currentScooter;
        try {
            ConcreteUI::callRUP(controller::PARK, scooter, user);
        }
        catch (const std::logic_error& exception)
        {
            cout << endl << "Error: " << exception.what() << endl;
            return;
        }
    }

    void MainUI::useScooter()
    {
        string identifier = enterID();
        try {
            ConcreteUI::getCurrentScooter(identifier);
        }
        catch (const std::logic_error& exception)
        {
            cout << endl << "Error: " << exception.what() << endl;
            return;
        }
        Scooter scooter = currentScooter;
        try {
            ConcreteUI::callRUP(controller::USE, scooter, user);
        }
        catch (const std::logic_error& exception)
        {
            cout << endl << "Error: " << exception.what() << endl;
            return;
        }
    }

    void MainUI::displayMyScooters()
    {
        ConcreteUI::callVectorAllScootersOfUser(this->user);
    }

    void MainUI::displayAllScootersSortedByModel()
    {
        ConcreteUI::callVectorSort(controller::SortedModel);
    }

    void MainUI::displayAllScootersSortedByKm()
    {
        ConcreteUI::callVectorSort(controller::SortedKm);
    }

    void MainUI::displayAllScootersSortedByLocation()
    {
        ConcreteUI::callVectorSort(controller::SortedLocation);
    }

    void MainUI::displayAllScootersSortedByStatus()
    {
        ConcreteUI::callVectorSort(controller::SortedStatus);
    }


} // ui