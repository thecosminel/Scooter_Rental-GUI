#include "Scooter.h"

#include <utility>
using scooter::ScooterStatus;

// Constructors & Destructors
scooter::Scooter::Scooter()
{
    this->identifier = "";
    this->model = "";
    this->manufacturingDate = "";
    this->kilometers = 0.0;
    this->location = "";
    this->status = UNKNOWN;
    this->user = "";
}

scooter::Scooter::Scooter(string identifier, string model, string date, double kilometers, string location, ScooterStatus status)
{
    this->identifier = std::move(identifier);
    this->model = std::move(model);
    this->manufacturingDate = std::move(date);
    this->kilometers = kilometers;
    this->location = std::move(location);
    this->status = status;
    this->user = "";
}

scooter::Scooter::Scooter(const scooter::Scooter &scooter)
{
    this->identifier = scooter.identifier;
    this->model = scooter.model;
    this->manufacturingDate = scooter.manufacturingDate;
    this->location = scooter.location;
    this->status = scooter.status;
    this->kilometers = scooter.kilometers;
    this->user = scooter.user;
}

scooter::Scooter &scooter::Scooter::operator=(const Scooter &scooter){
    if (this == &scooter)
        return *this;
    this->identifier = scooter.identifier;
    this->model = scooter.model;
    this->manufacturingDate = scooter.manufacturingDate;
    this->location = scooter.location;
    this->status = scooter.status;
    this->kilometers = scooter.kilometers;
    this->user = scooter.user;
    return *this;
}


// Getters
string scooter::Scooter::getIdentifier() const
{
    return this->identifier;
}

string scooter::Scooter::getModel() const
{
    return this->model;
}

string scooter::Scooter::getDate() const
{
    return this->manufacturingDate;
}

double scooter::Scooter::getKilometers() const
{
    return this->kilometers;
}

string scooter::Scooter::getLocation() const
{
    return this->location;
}

ScooterStatus scooter::Scooter::getStatus() const
{
    return this->status;
}

string scooter::Scooter::getUser() const
{
    return this->user;
}


// Setters
void scooter::Scooter::setIdentifier(string id)
{
    this->identifier = std::move(id);
}

void scooter::Scooter::setModel(string newModel)
{
    this->model = std::move(newModel);
}

void scooter::Scooter::setDate(string newDate)
{
    this->manufacturingDate = std::move(newDate);
}

void scooter::Scooter::setKilometers(double newKilometers)
{
    this->kilometers = newKilometers;
}

void scooter::Scooter::setLocation(string newLocation) //NOLINT
{
    this->location = std::move(newLocation);
}

void scooter::Scooter::setStatus(ScooterStatus newStatus)
{
    this->status = newStatus;
}

void scooter::Scooter::setUser(string newUser)
{
    this->user = std::move(newUser);
}

// Utils
bool scooter::Scooter::checkIfSameIdentifier(const Scooter &scooter)
{
    return this->identifier == scooter.identifier;
}

bool scooter::Scooter::checkIfNullScooter() //NOLINT
{
    if ( identifier.empty()
    && model.empty()
    && manufacturingDate.empty()
    && kilometers == 0.0
    && location.empty()
    && status == UNKNOWN
    )
        return true;
    return false;
}





