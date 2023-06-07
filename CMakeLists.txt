cmake_minimum_required(VERSION 3.25)
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
        Utils/data_validation_functions.h
        Utils/data_validation_functions.cpp
        AppRepository/ISubject.h
        AppRepository/ISubject.cpp
        AppController/IObserver.h
        AppController/IObserver.cpp
        AppRepository/CsvFileRepository.h
        AppRepository/CsvRepository.cpp
        AppController/AbstractController.h
        AppController/AbstractController.cpp
        AppController/ConcreteController.cpp
        AppController/ConcreteController.h
        AppUI/AbstractUI.cpp
        AppUI/AbstractUI.h
        AppUI/UI/ConcreteUI.cpp
        AppUI/UI/ConcreteUI.h
        AppUI/ISubject.cpp
        AppUI/ISubject.h
        Utils/UI_printFunctions.cpp
        Utils/UI_printFunctions.h
        AppUI/UI/MainUI.cpp
        AppUI/UI/MainUI.h
        Utils/UI_enterData.cpp
        Utils/UI_enterData.h
        AppRepository/repo_tests.cpp
        AppRepository/repo_tests.h
        AppController/ctrl_tests.cpp
        AppController/ctrl_tests.h)
