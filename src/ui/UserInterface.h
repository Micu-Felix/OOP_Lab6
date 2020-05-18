//
// Created by Bond on 4/10/2020.
//

/**
 * USER INTERFACE
 * @return
 */
#pragma once

#include "../controller/AdministratorController.h"
#include "../controller/BenutzerController.h"
class FilmUI {

private:
    AdministratorController* adm;
    BenutzerController* ben;
    static void show_menu(int modus);
    void AdministratorUI();
    void BenutzerUI();
    static std::string menu(int modus);
public:

    FilmUI();
    /*
     * Starts the UI with menu
     */
    void startUI();

};

