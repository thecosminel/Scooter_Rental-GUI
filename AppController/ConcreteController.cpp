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
        ui->printScooterContainer(scooters);
    }

    void ConcreteController::filterScootersByKmBetweenTwoValues(double kmMin, double kmMax)
    {
        auto scooters = repo->getAllScootersByKmBetweenTwoValues(kmMin, kmMax);
        ui->printScooterContainer(scooters);

    }

    void ConcreteController::filterScootersByAgeBetweenTwoDates(string dateMin, string dateMax)
    {
        auto scooters = repo->getAllScootersByAgeBetweenTwoDates(dateMin, dateMax);
        ui->printScooterContainer(scooters);
    }

    void ConcreteController::filterParkedScooters()
    {
        auto scooters = repo->getAllParkedScooters();
        ui->printScooterContainer(scooters);
    }


    // ----------------------------
    // Read - sort
    void ConcreteController::sortScootersByID()
    {
        auto scooters = repo->getAllScootersFromRepo();
        ui->printScooterContainer(scooters);
    }

    void ConcreteController::sortScootersByManufacturingDate()
    {
        auto scooters = repo->getAllScootersFromRepo();
        std::sort(scooters.begin(), scooters.end(), compareScooterByDate);
        ui->printScooterContainer(scooters);
    }

    // ------------------------------
    // IObserver override
    void ConcreteController::update(const string &data)
    {
        ui->printMessage(data);
    }

    void ConcreteController::logInAsManager(string user, string pass)
    {
        if (repo->checkManagerCredentials(user, pass))
        {
            ui->printMessage("Login as manager successful!");
        }
        else
        {
            throw std::invalid_argument("Manager username or password incorrect");
        }
    }

    void ConcreteController::scooterSetCurrent(string identifier)
    {
        Scooter requestedScooter = repo->getScooterById(identifier);
        if (requestedScooter.checkIfNullScooter())
        {
            throw std::logic_error("No scooter with matching ID");
        }
        ui->setCurrentScooter(requestedScooter);
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

    void ConcreteController::scooterVectorNoFiler(Operations operation)
    {
        switch (operation)
        {
            case SortedId:
                sortScootersByID();
                break;
            case SortedDate:
                sortScootersByManufacturingDate();
                break;
            case FilteredParked:
                filterParkedScooters();
                break;
            default:
                throw std::invalid_argument("Not a scooterVectorNoFile operation!!");
        }
    }

    void ConcreteController::scooterVectorFilterLocation(Operations operation, string location)
    {
        if (operation != FilteredLocation)
            throw std::invalid_argument("Not FilteredParked operation");
        filterScootersByLocation(location);
    }

    void ConcreteController::scooterVectorFilterDates(Operations operation, std::pair<string, string> dates)
    {
        if (operation != FilteredDates)
            throw std::invalid_argument("Not FilteredDates operation");
        filterScootersByAgeBetweenTwoDates(dates.first, dates.second);
    }

    void ConcreteController::scooterVectorFilterKm(Operations operation, std::pair<double, double> km)
    {
        if (operation != FilterKm)
            throw std::invalid_argument("Not FilterKm operation");
        filterScootersByKmBetweenTwoValues(km.first, km.second);
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