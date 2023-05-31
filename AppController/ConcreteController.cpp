#include "ConcreteController.h"

#include <utility>

namespace controller
{
    // ----------------------------
    // Constructors & destructors
    ConcreteController::ConcreteController(shared_ptr<CrudRepository> repo) : AbstractController(std::move(repo)) {}


    // ----------------------------
    // Create, Update, Delete
    void ConcreteController::addScooterToRepo(Scooter newScooter)
    {
        repo->addScooter(newScooter);
    }

    void ConcreteController::deleteScooterFomRepo(Scooter removedScooter)
    {
        repo->deleteScooter(removedScooter);
    }

    void ConcreteController::updateScooterFromRepo(Scooter updatedScooter)
    {
        repo->updateScooterInfo(updatedScooter);
    }

    void ConcreteController::reserveScooter(const string &ID, const string &username)
    {
        //TODO - Implementation
    }

    void ConcreteController::filterScootersByLocation(string location)
    {
        auto scooters = repo->getAllScootersByLocation(location);
        //TODO - Implementation
        // Print the result in UI
    }

    void ConcreteController::filterScootersByKmBetweenTwoValues(double kmMin, double kmMax)
    {
        auto scooters = repo->getAllScootersByKmBetweenTwoValues(kmMin, kmMax);
        //TODO - Implementation
        // Print the result in UI

    }

    void ConcreteController::filterScootersByAgeBetweenTwoDates(string dateMin, string dateMax)
    {
        auto scooters = repo->getAllScootersByAgeBetweenTwoDates(dateMin, dateMax);
        //TODO - Implementation
        // Print the result in UI
    }

    void ConcreteController::filterParkedScooters()
    {
        auto scooters = repo->getAllParkedScooters();
        //TODO - Implementation
        // Print the result in UI
    }


    // ----------------------------
    // Read - sort
    void ConcreteController::sortScootersByID()
    {
        auto scooters = repo->getAllScootersFromRepo();
        //TODO - Implementation
        // Print the result in UI
    }

    void ConcreteController::sortScootersByManufacturingDate()
    {
        auto scooters = repo->getAllScootersFromRepo();
        //TODO - Implementation
        // Sort by date
        // Print the result in UI
    }


} // controller