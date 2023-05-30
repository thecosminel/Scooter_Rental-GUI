#ifndef SCOOTER_RENTAL_GUI_ABSTRACTCONTROLLER_H
#define SCOOTER_RENTAL_GUI_ABSTRACTCONTROLLER_H

#include "../AppRepository/InMemoryRepository.h"
#include "IObserver.h"

#include "memory"

using repository::CrudRepository;
using std::shared_ptr;

namespace controller {

    class AbstractController : public IObserver{
    private:
        shared_ptr<CrudRepository> repo;

    public:
        explicit AbstractController(shared_ptr<CrudRepository> repo);
    };

} // controller

#endif //SCOOTER_RENTAL_GUI_ABSTRACTCONTROLLER_H
