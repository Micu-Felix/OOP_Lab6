cmake_minimum_required(VERSION 3.15)
project(Lab6)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6 APP.cpp AdministratorController.cpp AdministratorController.h BenutzerController.cpp BenutzerController.h Film.h Repository.h UserInterface.cpp UserInterface.h Tests.cpp Tests.h Repository.cpp)