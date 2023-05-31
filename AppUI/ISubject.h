#ifndef SCOOTER_RENTAL_GUI_ISUBJECT_H
#define SCOOTER_RENTAL_GUI_ISUBJECT_H

#include <../AppController/IObserver.h>

#include <set>
#include <memory>

using controller::IObserver;
using std::set, std::shared_ptr, std::string;

namespace ui {

    class ISubject {
    private:
        set<shared_ptr<IObserver>> observers;

    public:
        ISubject() = default;

        void attach(const shared_ptr<IObserver>& newObserver);

        void detach(const shared_ptr<IObserver>& removedObserver);

        void notify(const string& data);
    };

} // ui

#endif //SCOOTER_RENTAL_GUI_ISUBJECT_H
