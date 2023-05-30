#ifndef SCOOTER_RENTAL_GUI_IOBSERVER_H
#define SCOOTER_RENTAL_GUI_IOBSERVER_H

#include <string>

using std::string;

namespace controller {

    class IObserver {
    public:
        virtual void update(const string& data) = 0;
    };

}

#endif //SCOOTER_RENTAL_GUI_IOBSERVER_H
