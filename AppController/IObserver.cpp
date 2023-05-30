#include "IObserver.h"

#include <iostream>
using std::cout;

namespace controller
{


    void IObserver::update(const string &data)// NOLINT
    {
        cout << data;
    }
}