cmake_minimum_required(VERSION 3.25)
project(ScooterRental_GUI)

set(CMAKE_CXX_STANDARD 20)

include_directories(Domain)

add_executable(ScooterRental_GUI
        Main.cpp
        Domain/Scooter.cpp
        Domain/Scooter.h
        AppRepository/CrudRepository.h
        AppRepository/CrudRepository.cpp)