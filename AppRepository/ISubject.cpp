#include "ISubject.h"

namespace repository
{

    void ISubject::attach(const shared_ptr<IObserver>& newObserver)
    {
        observers.insert(newObserver);
    }

    void ISubject::detach(const shared_ptr<IObserver>& removedObserver)
    {
        auto it = std::find(observers.begin(), observers.end(), removedObserver);
        if (it != observers.end())
        {
            observers.erase(it);
        }
    }

    void ISubject::notify(const string &data)
    {
        for (const auto& observer : observers) {
            observer->update(data);
        }
    }
}