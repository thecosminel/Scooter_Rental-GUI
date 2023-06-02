#include "CrudRepository.h"

using scooter::Scooter;

namespace repository
{

    CrudRepository &repository::CrudRepository::operator=(const repository::CrudRepository &other){
        if (this == &other)
        {
            return *this;
        }

        // Perform deep copy of the Scooters vector
        scooters = other.scooters;

        return *this;
    }



}
