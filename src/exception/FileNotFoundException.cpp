//
// Created by Bond on 5/18/2020.
//

#ifndef LAB6_FILENOTFOUNDEXCEPTION_CPP
#define LAB6_FILENOTFOUNDEXCEPTION_CPP
#import <exception>
#import <string>
using namespace std;
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

#endif //LAB6_FILENOTFOUNDEXCEPTION_CPP
