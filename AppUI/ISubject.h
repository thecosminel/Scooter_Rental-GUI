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

        virtual void tryToLogAsManager(string user, string pass) = 0;

        virtual void tryToLogAsUser(string user, string pass) = 0;

        virtual void createUserAccount(string user, string pass) = 0;

        virtual void requestScooter (string identifier) = 0;

        /// Add, update, remove scooter
        /// \param operation
        /// \param scooter
        virtual void callCUD(Operations operation, const Scooter& scooter) = 0;

        virtual void callRUP(Operations operation, const Scooter& scooter, string user) = 0;

        virtual void callVectorAllScootersOfUser(string userName) = 0;

        virtual void callVectorSort(Operations operation) = 0;

        virtual void callFilterLocation(Operations operations, string location) = 0;

        virtual void callFilterDates(Operations operation, std::pair<string, string> dates) = 0;

        virtual void callFilterKm(Operations operation, std::pair<double, double> km) = 0;
    };

} // ui

#endif //SCOOTER_RENTAL_GUI_ISUBJECTUI_H
