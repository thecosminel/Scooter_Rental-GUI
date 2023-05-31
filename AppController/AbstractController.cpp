#include "AbstractController.h"

namespace controller
{
    enum controllerOperations {
        ADD,
        DELETE,
        UPDATE
    };

    AbstractController::AbstractController(shared_ptr<CrudRepository> repo, shared_ptr<AbstractUI> ui)
    {
        this->repo = repo; // NOLINT
        this->ui = ui; //NOLINT
    }
}