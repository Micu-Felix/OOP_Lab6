#include <iostream>

using namespace std;

#include "src/ui/FilmUI.h"

int main() {
    auto* ui = new FilmUI{};
    ui->startUI();
}
