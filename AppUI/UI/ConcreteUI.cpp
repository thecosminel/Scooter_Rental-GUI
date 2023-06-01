#include "ConcreteUI.h"


namespace ui {


    void ConcreteUI::printScooterContainer(vector<Scooter> scooters)
    {
        Scooter scooter;
        cout << endl;
        for (int i = 0; i < scooters.size(); ++i)
        {
            scooter = scooters[i];
            printIndexing(i);
            cout << "ID: " << scooter.getIdentifier() << "  ";
            cout << "Model: " << scooter.getModel();
            insertBlankSpaces(scooter.getModel());
            cout << "Commissioning date: " << scooter.getDate();
            insertBlankSpaces(scooter.getDate());
            cout << "Km: ";
            printDoubleNumber(scooter.getKilometers());
            cout << "Location: " << scooter.getLocation();
            insertBlankSpaces(scooter.getLocation());
            cout << "Status: " << getScooterStatusString(scooter.getStatus());
            cout << endl;
        }
        cout << endl;
    }

    void ConcreteUI::printMessage(string message)
    {
        cout << endl << endl;
        cout << "Message: " << message << endl;
    }

    // ------------------------
    // ISubject
    void ConcreteUI::callCUD(Operations operation, const Scooter &scooter)
    {
        for (const auto& observer : observers)
        {
            observer->scooterCUD(operation, scooter);
        }
    }

    void ConcreteUI::callVectorNoFiler(Operations operation)
    {
        for (const auto& observer : observers)
        {
            observer->scooterVectorNoFiler(operation);
        }
    }

    void ConcreteUI::callFilterLocation(Operations operation, string location)
    {
        for (const auto& observer : observers)
        {
            observer->scooterVectorFilterLocation(operation, location);
        }
    }

    void ConcreteUI::callFilterDates(Operations operation, std::pair<string, string> dates)
    {
        for (const auto& observer : observers)
        {
            observer->scooterVectorFilterDates(operation, dates);
        }
    }


} // ui