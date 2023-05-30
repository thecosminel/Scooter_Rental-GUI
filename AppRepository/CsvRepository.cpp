#include "CsvFileRepository.h"

namespace repository
{
    // Constructors & destructors
    CsvFileRepository::CsvFileRepository(const string &fileName) : InMemoryRepository(fileName){}

    CsvFileRepository::~CsvFileRepository()
    {
        saveToFile();
    }

    CsvFileRepository &CsvFileRepository::operator=(const CsvFileRepository &other){
        if (this == &other)
        {
            return *this;
        }
        // Perform deep copy of the Scooters vector
        scooters = other.scooters;
        return *this;
    }


    // Other
    void CsvFileRepository::saveToFile()
    {
        std::ofstream file(dataFileName);
        if (file.is_open())
        {
            file << scooters.size() << std::endl;
            for (const auto& scooter : scooters) {
                file << scooter.getIdentifier() << ',';
                file << scooter.getModel() << ',';
                file << scooter.getDate() << ',';
                file << scooter.getKilometers() << ',';
                file << scooter.getLocation() << ',';
                file << static_cast<int>(scooter.getStatus()) << std::endl;
            }
            file.close();
        }
    }

}