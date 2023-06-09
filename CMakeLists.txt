cmake_minimum_required(VERSION 3.24.2)
project(ScooterRental_GUI)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Qt5_DIR "C:/Qt/5.15.14/mingw81_64/lib/cmake/Qt5")
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(Domain)

add_executable(ScooterRental_GUI
        Main.cpp
        AppUI/GUI/MainGUI.h AppUI/GUI/MainGUI.cpp
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
        AppRepository/CsvFileRepository.cpp
        AppController/AbstractController.h
        AppController/AbstractController.cpp
        AppController/ConcreteController.cpp
        AppController/ConcreteController.h
        AppUI/AbstractUI.cpp
        AppUI/AbstractUI.h
        AppUI/ConcreteUI.cpp
        AppUI/ConcreteUI.h
        AppUI/ISubject.cpp
        AppUI/ISubject.h
        Utils/UI_printFunctions.cpp
        Utils/UI_printFunctions.h
        AppUI/UI/MainUI.cpp
        AppUI/UI/MainUI.h
        Utils/UI_enterData.cpp
        Utils/UI_enterData.h
        Tests/repo_tests.cpp
        Tests/repo_tests.h
        Tests/ctrl_tests.cpp
        Tests/ctrl_tests.h Utils/GUI_enterData.h Utils/GUI_enterData.cpp Utils/GUI_printFunctions.h Utils/GUI_printFunctions.cpp)

target_link_libraries(ScooterRental_GUI Qt5::Widgets)