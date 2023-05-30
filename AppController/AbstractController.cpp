#include "AbstractController.h"

namespace controller
{


    AbstractController::AbstractController(shared_ptr<CrudRepository> repo)
    {
        this->repo = repo; // NOLINT
    }
}