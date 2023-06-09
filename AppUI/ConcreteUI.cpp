#include "ConcreteUI.h"


namespace ui {

    // ------------------------
    // Getters & setters
    void ConcreteUI::getCurrentScooter(string identifier)
    {
        for (const auto& observer : observers)
        {
            observer->scooterSetCurrent(identifier);
        }
    }

    void ConcreteUI::setCurrentScooter(Scooter scooter)
    {
        this->currentScooter = scooter;
    }



    // ------------------------
    // ISubject
    void ConcreteUI::tryToLogAsManager(string user, string pass)
    {
        for (const auto& observer : observers)
        {
            observer->logInAsManager(user, pass);
        }
    }

    void ConcreteUI::tryToLogAsUser(string user, string pass)
    {
        for (const auto& observer : observers)
        {
            observer->logInAsUser(user, pass);
        }
    }

    void ConcreteUI::createUserAccount(string user, string pass)
    {
        for (const auto& observer : observers)
        {
            observer->createUserAccount(user, pass);
        }
    }

    void ConcreteUI::requestScooter(string identifier)
    {
        for (const auto& observer : observers)
        {
            observer->scooterSetCurrent(identifier);
        }
    }

    void ConcreteUI::callCUD(Operations operation, const Scooter &scooter)
    {
        for (const auto& observer : observers)
        {
            observer->scooterCUD(operation, scooter);
        }
    }

    void ConcreteUI::callRUP(Operations operation, const Scooter &scooter, string user)
    {
        for (const auto& observer : observers)
        {
            observer->scooterRUP(operation, scooter, user);
        }
    }

    void ConcreteUI::callVectorAllScootersOfUser(string userName)
    {
        for (const auto& observer : observers)
        {
            observer->displayAllScootersOfAnUser(userName);
        }
    }

    void ConcreteUI::callVectorSort(Operations operation)
    {
        for (const auto& observer : observers)
        {
            observer->scooterVectorSorted(operation);
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

    void ConcreteUI::callFilterKm(Operations operation, std::pair<double, double> km)
    {
        for (const auto& observer : observers)
        {
            observer->scooterVectorFilterKm(controller::FilterKm, km);
        }
    }




} // ui