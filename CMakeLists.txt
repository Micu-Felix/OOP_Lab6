cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(OOP_Lab6)

set(SOURCE_FILES
        src/domain/Film.h
        src/repository/FilmRepository.h
        src/repository/FilmInMemoryRepository.cpp
        src/repository/FilmFileRepository.cpp
        src/controller/AdministratorController.h
        src/controller/AdministratorController.cpp
        src/ui/FilmUI.h
        src/ui/FilmUI.cpp
        src/exceptions/exceptions.cpp
        main.cpp src/controller/BenutzerController.cpp src/controller/BenutzerController.h
        src/validation/validation.h)
add_executable(lab_6_run ${SOURCE_FILES})
FILE(COPY resources/filme.csv DESTINATION "${CMAKE_BINARY_DIR}/resources")
FILE(COPY test/resources/filme.csv DESTINATION "${CMAKE_BINARY_DIR}/test/resources")

add_subdirectory(test)