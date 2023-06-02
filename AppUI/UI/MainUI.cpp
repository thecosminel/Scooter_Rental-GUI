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
            cout << "  9. Display all parked scooters" << endl;
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
                    deleteExistingScooter();
                    break;
                case '3':
                    cout << "Modify existing scooter: ";
                    modifyExistingScooter();

                    break;
                case '4':
                    cout << "Search scooter by location: ";
                    searchScooterByLocation();
                    break;
                case '5':
                    cout << "Display scooters with km between:  ";
                    displayScootersFilteredByKm();
                    break;
                case '6':
                    cout << "Display scooters with manufacturing date between:  ";
                    displayScootersFilteredByDates();
                    break;
                case '7':
                    cout << "Display all scooters sorted ascending by age: ";
                    displayAllScootersSortedByAge();
                    break;
                case '8':
                    cout << "Display all scooters sorted ascending by ID: ";
                    displayAllScootersSortedByID();
                    break;
                case '9':
                    cout << "Display all parked scooters: ";
                    displayAllParkedScooters();
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
        //logIn();
        //TODO - Implementation
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
        ConcreteUI::callVectorNoFiler(controller::SortedDate);
    }

    void MainUI::displayAllScootersSortedByID()
    {
        ConcreteUI::callVectorNoFiler(controller::SortedId);
    }

    void MainUI::displayAllParkedScooters()
    {
        ConcreteUI::callVectorNoFiler(controller::FilteredParked);
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

} // ui