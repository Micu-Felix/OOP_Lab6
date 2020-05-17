cmake_minimum_required(VERSION 3.15)
project(Lab6)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6 APP.cpp Administrator.cpp Administrator.h Benutzer.cpp Benutzer.h Film.h Repository.h UserInterface.cpp UserInterface.h Tests.cpp Tests.h)