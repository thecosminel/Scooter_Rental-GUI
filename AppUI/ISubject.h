#ifndef SCOOTER_RENTAL_GUI_ISUBJECTUI_H
#define SCOOTER_RENTAL_GUI_ISUBJECTUI_H

#include <../AppController/IObserver.h>

#include <set>
#include <memory>

using controller::IObserver;
using controller::Operations;
using controller::ADD, controller::UPDATE, controller::REMOVE;
using controller::Operations;
using std::set, std::shared_ptr, std::string;

namespace ui {

    class ISubject {
    protected:
        set<shared_ptr<IObserver>> observers;

    public:
        ISubject() = default;

        void attach(const shared_ptr<IObserver>& newObserver);

        void detach(const shared_ptr<IObserver>& removedObserver);

        void notify(const string& data);

        /// Add, update, remove scooter
        /// \param operation
        /// \param scooter
        virtual void callCUD(Operations operation, const Scooter& scooter) = 0;
    };

} // ui

#endif //SCOOTER_RENTAL_GUI_ISUBJECTUI_H
