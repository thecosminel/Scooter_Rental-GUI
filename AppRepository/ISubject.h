#ifndef SCOOTER_RENTAL_GUI_ISUBJECT_H
#define SCOOTER_RENTAL_GUI_ISUBJECT_H

#include "../AppController/IObserver.h"

#include <set>

using controller::IObserver;
using std::set;

namespace repository {

    class ISubject {
    private:
        set<IObserver*> observers;

    public:
        void attach(IObserver* newObserver);

        void detach(IObserver* removedObserver);

        void notify(const std::string& data);
    };

} // repository

#endif //SCOOTER_RENTAL_GUI_ISUBJECT_H
