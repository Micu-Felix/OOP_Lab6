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
    void addToWatchlist(const Film& film){ben->addToWatchlist(film);};
public:

    FilmUI();
    /*
     * Starts the UI with menu
     */
    void startUI();

};

