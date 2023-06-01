#include "ConcreteController.h"

#include <utility>

namespace controller
{
    // ----------------------------
    // Constructors & destructors
    ConcreteController::ConcreteController(shared_ptr<CrudRepository> repo, shared_ptr<AbstractUI> ui) : AbstractController(std::move(repo), std::move(ui)) {}


    // ----------------------------
    // Create, Update, Delete
    void ConcreteController::addScooterToRepo(Scooter newScooter)
    {
        string newIdentifier = generateNewId();
        newScooter.setIdentifier(newIdentifier);
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

    // ------------------------------
    // IObserver override
    void ConcreteController::update(const string &data)
    {
        ui->printMessage(data);
    }

    void ConcreteController::scooterCUD(Operations operation, const Scooter& scooter)
    {
        switch (operation)
        {
            case ADD:
                addScooterToRepo(scooter);
                break;
            case REMOVE:
                deleteScooterFomRepo(scooter);
                break;
            case UPDATE:
                updateScooterFromRepo(scooter);
                break;
            default:
                throw std::invalid_argument("Not a CUD operation!!");
        }
    }

    // Utils
    string ConcreteController::generateNewId()
    {
        vector<string> allIdsInRepo = repo->getAllIdentifiers();
        string newId;
        bool usable;
        do 
        {
            newId = generateRandomID();
            usable = true;
            for (const auto& id : allIdsInRepo)
            {
                if (newId == id)
                {
                    usable = false;
                    break;
                }
            }
            if (usable)
            {
                return newId;
            }
        } while (true);
    }


} // controller