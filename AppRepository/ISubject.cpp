#include "ISubject.h"

namespace repository
{

    void ISubject::attach(IObserver *newObserver)
    {
        observers.insert(newObserver);
    }

    void ISubject::detach(IObserver *removedObserver)
    {
        auto it = std::find(observers.begin(), observers.end(), removedObserver);
        if (it != observers.end())
        {
            observers.erase(it);
        }
    }

    void ISubject::notify(const string &data)
    {
        for (auto observer : observers) {
            observer->update(data);
        }
    }
}