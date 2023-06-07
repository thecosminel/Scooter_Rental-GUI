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
        if (!loggedManager)
        {
            throw std::logic_error("Not logged in!!");
        }
        string newIdentifier = generateNewId();
        newScooter.setIdentifier(newIdentifier);
        repo->addScooter(newScooter);
    }

    void ConcreteController::deleteScooterFomRepo(Scooter removedScooter)
    {
        if (!loggedManager)
        {
            throw std::logic_error("Not logged in!!");
        }
        repo->deleteScooter(removedScooter);
    }

    void ConcreteController::updateScooterFromRepo(Scooter updatedScooter)
    {
        if (!loggedManager)
        {
            throw std::logic_error("Not logged in!!");
        }
        repo->updateScooterInfo(updatedScooter);
    }

    void ConcreteController::reserveScooter(Scooter scooter, const string &username)
    {
        if (!loggedUser)
        {
            throw std::logic_error("Not logged in!!");
        }
        repo->reserveScooter(scooter, username);
    }

    void ConcreteController::useScooter(Scooter usedScooter, const string &username)
    {
        if (!loggedUser)
        {
            throw std::logic_error("Not logged in!!");
        }
        repo->useScooter(usedScooter, username);
    }

    void ConcreteController::parkScooter(Scooter toParkScooter, const string& username)
    {
        if (!loggedUser)
        {
            throw std::logic_error("Not logged in!!");
        }
        repo->parkScooter(toParkScooter, username);
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
        std::sort(scooters.begin(), scooters.end(), utils::compareScooterById);
        ui->printScooterContainer(scooters);
    }

    void ConcreteController::sortScootersByManufacturingDate()
    {
        auto scooters = repo->getAllScootersFromRepo();
        std::sort(scooters.begin(), scooters.end(), compareScooterByDate);
        ui->printScooterContainer(scooters);
    }

    void ConcreteController::sortScootersByModel()
    {
        auto scooters = repo->getAllScootersFromRepo();
        std::sort(scooters.begin(), scooters.end(), utils::compareScooterByModel);
        ui->printScooterContainer(scooters);
    }

    void ConcreteController::sortScootersByKm()
    {
        auto scooters = repo->getAllScootersFromRepo();
        std::sort(scooters.begin(), scooters.end(), utils::compareScooterByKm);
        ui->printScooterContainer(scooters);
    }

    void ConcreteController::sortScootersByLocation()
    {
        auto scooters = repo->getAllScootersFromRepo();
        std::sort(scooters.begin(), scooters.end(), utils::compareScooterByLocation);
        ui->printScooterContainer(scooters);
    }

    void ConcreteController::sortScootersByStatus()
    {
        auto scooters = repo->getAllScootersFromRepo();
        std::sort(scooters.begin(), scooters.end(), utils::compareScooterByStatus);
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
            loggedManager = true;
            ui->printMessage("Login as manager successful!");
        }
        else
        {
            throw std::invalid_argument("Manager username or password incorrect");
        }
    }

    void ConcreteController::logInAsUser(string user, string pass)
    {
        if (repo->checkUserCredentials(user, pass))
        {
            loggedUser = true;
            ui->printMessage("Login as client successful!");
        }
        else
        {
            throw std::invalid_argument("Client username or password incorrect");
        }
    }

    void ConcreteController::createUserAccount(string user, string pass)
    {
        repo->createUserAccount(user, pass);
    }

    void ConcreteController::scooterSetCurrent(string identifier)
    {
        Scooter requestedScooter = repo->getScooterById(identifier);
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

    void ConcreteController::scooterRUP(Operations operation , const Scooter& scooter, string user)
    {
        switch (operation)
        {

            case RESERVE:
                reserveScooter(scooter, user);
                break;
            case USE:
                useScooter(scooter, user);
                break;
            case PARK:
                parkScooter(scooter, user);
                break;
            default:
                throw std::invalid_argument("Not a RUP operation!!");
        }

    }

    void ConcreteController::displayAllScootersOfAnUser(string user)
    {
        if (!loggedUser)
        {
            throw std::logic_error("Not logged in!!");
        }
        auto scooters = repo->getAllScootersOfAnUser(user);
        ui->printScooterContainer(scooters);
    }

    void ConcreteController::scooterVectorSorted(Operations operation)
    {
        switch (operation)
        {
            case SortedId:
                sortScootersByID();
                break;
            case SortedModel:
                sortScootersByModel();
                break;
            case SortedDate:
                sortScootersByManufacturingDate();
                break;
            case SortedKm:
                sortScootersByKm();
                break;
            case SortedLocation:
                sortScootersByLocation();
                break;
            case SortedStatus:
                sortScootersByStatus();
                break;
            case FilteredParked:
                filterParkedScooters();
                break;
            default:
                throw std::invalid_argument("Not a SortScooters operation!!");
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