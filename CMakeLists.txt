cmake_minimum_required(VERSION 3.15)
project(Lab6)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES APP.cpp src/controller/AdministratorController.cpp
        src/controller/AdministratorController.h src/controller/BenutzerController.cpp
        src/controller/BenutzerController.h src/domain/Film.h src/ui/UserInterface.cpp
        src/ui/UserInterface.h Tests.cpp Tests.h src/repository/RepositoryInMemory.cpp
        src/exception/FileNotFoundException.cpp src/repository/FilmFileRepository.cpp
        src/repository/FilmRepository.h)

add_executable(Lab6_run ${SOURCE_FILES})
FILE(COPY resources/filme.csv DESTINATION "${CMAKE_BINARY_DIR}/resources")