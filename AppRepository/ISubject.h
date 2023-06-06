#ifndef SCOOTER_RENTAL_GUI_ISUBJECT_H
#define SCOOTER_RENTAL_GUI_ISUBJECT_H

#include "../AppController/IObserver.h"

#include <set>
#include <memory>

using controller::IObserver;
using std::set, std::shared_ptr, std::string;

namespace repository {

    class ISubject {
    private:
        set<shared_ptr<IObserver>> observers;

    public:
        ISubject() = default;

        /// Attach
        /// \param newObserver
        void attach(const shared_ptr<IObserver>& newObserver);

        /// Detach
        /// \param removedObserver
        void detach(const shared_ptr<IObserver>& removedObserver);

        /// Notify
        /// \param data
        void notify(const string& data);
    };

} // repository

#endif //SCOOTER_RENTAL_GUI_ISUBJECT_H
