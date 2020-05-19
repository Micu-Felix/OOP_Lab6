project(test)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCE_FILES
        ../src/domain/Film.h
        ../src/repository/FilmRepository.h
        ../src/repository/FilmInMemoryRepository.cpp
        ../src/controller/AdministratorController.h
        ../src/controller/AdministratorController.cpp)
add_executable(Google_Tests_run ControllerTest.cpp ${SOURCE_FILES})
target_link_libraries(Google_Tests_run gtest gtest_main)