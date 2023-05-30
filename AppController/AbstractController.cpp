#include "AbstractController.h"

namespace controller
{
    enum controllerOperations {
        ADD,
        DELETE,
        UPDATE
    };

    AbstractController::AbstractController(shared_ptr<CrudRepository> repo)
    {
        this->repo = repo; // NOLINT
    }
}