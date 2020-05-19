#include <exception>
#include <string>

#pragma once
using namespace std;

/**
 * checks for any exceptions that could appear along the program
 */
class FileNotFoundException : exception {
private:
    string fileName;
public:
    explicit FileNotFoundException(std::string fileName) : exception() {
        this->fileName = std::move(fileName);
    }

    const char *what() const noexcept override {
        return ("File " + fileName + " was not found").c_str();
    }
};

class FilmNotFoundException : exception {

private:
    std::string titlu;
public:

    explicit FilmNotFoundException(std::string titlu) : std::exception() {
        this->titlu = std::move(titlu);

    }

    const char *what() const noexcept override {
        return (titlu + " existiert nicht!").c_str();

    }
};

class InvalidURL : std::exception {
public:
    const char *what() const noexcept override {
        return "falsches URL";
    }

};