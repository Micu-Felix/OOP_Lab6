#include <iostream>
#include "src/ui/UserInterface.h"
#include "Tests.h"
int main() {

    std::cout << "Hello, Lab5!" << std::endl;
    //Teste();
    auto ui=new FilmUI();
    ui->startUI();
    return 0;
}
