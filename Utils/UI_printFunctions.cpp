#include "UI_printFunctions.h"

namespace utils {
    void printIndexing(int index)
    {
        if (index < 10)
        {
            cout << 0 << index << "-> ";
        }
        else
        {
            cout << index << "-> ";
        }
    }

    void insertBlankSpaces(const string& text)
    {
        unsigned long long length = text.size();
        for (unsigned long long  i = length; i < 12; ++i)
        {
            cout << ' ';
        }
    }

    void printDoubleNumber(double number)
    {
        int intValueOfNumber;
        intValueOfNumber = static_cast<int>(number);
        if (intValueOfNumber < 100000)
            cout << ' ';
        if (intValueOfNumber < 10000)
            cout << ' ';
        if (intValueOfNumber < 1000)
            cout << ' ';
        if (intValueOfNumber < 100)
            cout << ' ';
        if (intValueOfNumber < 10)
            cout << ' ';
        cout << intValueOfNumber;
        cout << '.';
        if (static_cast<int>(number * 100) % 100 < 10)
            cout << 0;
        cout << static_cast<int>(number * 100) % 100;
        cout << " ";
    }

    string getScooterStatusString(ScooterStatus status)
    {
        switch (status) {
            case scooter::PARKED:
                return "PARKED";
            case scooter::RESERVED:
                return "RESERVED";
            case scooter::IN_USE:
                return "IN_USE";
            case scooter::MAINTENANCE:
                return "MAINTENANCE";
            case scooter::OUT_OF_SERVICE:
                return "OUT_OF_SERVICE";
            default:
                return "UNKNOWN";
        }
    }
}