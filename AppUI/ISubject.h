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

        /// Attatch observer
        /// \param newObserver
        void attach(const shared_ptr<IObserver>& newObserver);

        /// Detach observer
        void detach(const shared_ptr<IObserver>& removedObserver);

        /// Notify observer
        void notify(const string& data);

        /// Log in as manager
        /// \param user
        /// \param pass
        virtual void tryToLogAsManager(string user, string pass) = 0;

        /// Log in as user
        /// \param user
        /// \param pass
        virtual void tryToLogAsUser(string user, string pass) = 0;

        /// Create user acc
        /// \param user
        /// \param pass
        virtual void createUserAccount(string user, string pass) = 0;

        /// Request scooter
        /// \param identifier
        virtual void requestScooter (string identifier) = 0;

        /// Add, update, remove scooter
        /// \param operation
        /// \param scooter
        virtual void callCUD(Operations operation, const Scooter& scooter) = 0;

        /// Blah blah blah
        /// \param operation
        /// \param scooter
        /// \param user
        virtual void callRUP(Operations operation, const Scooter& scooter, string user) = 0;

        /// Get all of user
        /// \param userName
        virtual void callVectorAllScootersOfUser(string userName) = 0;

        /// Sort by attribute
        /// \param operation
        virtual void callVectorSort(Operations operation) = 0;

        /// Filter loc
        /// \param operations
        /// \param location
        virtual void callFilterLocation(Operations operations, string location) = 0;

        /// Filter date
        /// \param operation
        /// \param dates
        virtual void callFilterDates(Operations operation, std::pair<string, string> dates) = 0;

        /// Filter km
        /// \param operation
        /// \param km
        virtual void callFilterKm(Operations operation, std::pair<double, double> km) = 0;
    };

} // ui

#endif //SCOOTER_RENTAL_GUI_ISUBJECTUI_H
