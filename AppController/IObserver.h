#ifndef SCOOTER_RENTAL_GUI_IOBSERVER_H
#define SCOOTER_RENTAL_GUI_IOBSERVER_H

#include "../Domain/Scooter.h"

#include <string>

using scooter::Scooter;
using std::string;

#include <iostream>
using std::cout;

namespace controller {

    enum Operations{
        ADD,
        REMOVE,
        UPDATE,
        SortedId,
        SortedDate
    };

    class IObserver {
    public:
        IObserver() = default;

        virtual void update(const string& data) = 0;
//        void update(const string& data);

        virtual void scooterCUD(Operations operation, const Scooter& scooter) = 0;

    };

}

#endif //SCOOTER_RENTAL_GUI_IOBSERVER_H
