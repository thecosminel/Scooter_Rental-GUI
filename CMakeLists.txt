cmake_minimum_required(VERSION 3.24.2)
project(ScooterRental_GUI)

set(CMAKE_CXX_STANDARD 20)

include_directories(Domain)

add_executable(ScooterRental_GUI
        Main.cpp
        Domain/Scooter.cpp
        Domain/Scooter.h
        AppRepository/CrudRepository.h
        AppRepository/CrudRepository.cpp
        AppRepository/InMemoryRepository.h
        AppRepository/InMemoryRepository.cpp
        Utils/auxiliaryFunctions.h
        Utils/auxiliaryFunctions.cpp
        AppRepository/ISubject.h
        AppRepository/ISubject.cpp
        AppController/IObserver.h
        AppController/IObserver.cpp
        AppRepository/CsvFileRepository.h
        AppRepository/CsvRepository.cpp
        AppController/AbstractController.h
        AppController/AbstractController.cpp AppController/ConcreteController.cpp AppController/ConcreteController.h)
