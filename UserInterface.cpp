//
// Created by Bond on 4/10/2020.
//
#include <string>
#include <iostream>
#include "AdministratorController.h"
#include "BenutzerController.h"
#include <stdlib.h>
#include <typeinfo>
#include <algorithm>
#include <windows.h>
#include <shellapi.h>

std::string menu(int modus) {
    std::string aux;
    if (modus == 1)
        aux = "\nMenu AdministratorController :-)\n"
              "Wahlen Sie eine Option: \n"
              "1 - Einfugen\n"
              "2 - Bearbeitung der Daten\n"
              "3 - Loschen\n"
              "4 - Liste Filme ansehen\n"
              "0 - Exit\n"
              "\n";
    else
        aux = "\nMenu BenutzerController :-)\n"
              "Wahlen Sie eine Option: \n"
              "1 - Genre suchen\n"
              "2 - Loschen(und sich einen Film anschauen)\n"
              "0 - Exit\n"
              "\n";

    return aux;
}

void valid() {
    if (!cin) {
        cin.clear();
        cout << "Schlechter Input!!! \n";
        exit(EXIT_FAILURE);

    }
}

bool UI() {
    int modus;
    std::cout
            << "In welchen Modus mochten sie das Programm starten? 1 fur Adminstr. oder 2 fur BenutzerController: ?????\n\n";
    std::cin >> modus;
    valid();
    if (modus == 1 || modus == 2)
        std::cout << menu(modus);
    else
        return false;
    int option;
    std::string titel, genre, trailer;
    int jahr, likes;
    std::string new_link;
    auto adm = new AdministratorController();
    if (modus == 1) {

        while (true) {
            std::cout << "Option:\n";
            std::cin >> option;
            valid();
            switch (option) {
                case 0:
                    return false;
                case 1:
                    std::cout << "\nGeben Sie den Titel des Films ein: ";
                    std::cin >> titel;
                    valid();
                    std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein: ";
                    std::cin >> jahr;
                    valid();
                    std::cout << "\nGeben Sie das Genre des Films ein: ";
                    std::cin >> genre;
                    valid();
                    std::cout << "\nGeben Sie den Link des Trailes des Films ein: ";
                    std::cin >> trailer;
                    valid();
                    std::cout << "\nGeben Sie die Anzahl von Likes des Films ein: ";
                    std::cin >> likes;
                    valid();
                    if (!adm->add_film(Film(titel, genre, jahr, likes, trailer)))
                        std::cout << "Es gibt schon diesen Film\n";
                    else
                        cout << "Film wurde eingefugt !!\n";

                    break;
                case 2:
                    std::cout << "\nGeben Sie den Titel des Films ein, den Sie bearbeiten mochten: ";
                    std::cin >> titel;
                    valid();
                    std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein, den Sie bearbeiten mochten:  ";
                    std::cin >> jahr;
                    valid();
                    std::cout << "\nGeben Sie den neuen Link des Films ein:  ";
                    std::cin >> new_link;
                    valid();
                    if (!adm->edit_film(titel, jahr, new_link))
                        std::cout << "Es gibt keine solchen Film\n";
                    else
                        cout << "Erfolgreiche Bearbeitung der Daten !!\n";
                    break;
                case 3:

                    std::cout << "\nGeben Sie den Titel des Films ein, den Sie loschen mochten: ";
                    std::cin >> titel;
                    valid();
                    std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein, den Sie loschen mochten:  ";
                    std::cin >> jahr;
                    valid();
                    if (adm->delete_film(titel, jahr))
                        cout << "Film wurde erfolgreich geloscht !!\n";
                    else
                        cout << "Es gibt diesen Film nicht !!\n";
                    break;
                case 4:
                    std::cout << "In der Datenbank gibt es folgende Filme: \n";
                    for (auto &iter : adm->view_filme()) {
                        cout << iter.anschreiben();
                    }
                default:
                    break;

            }
        }
    } else {
        auto ben = new BenutzerController();
        vector<Film> filme;
        while (true) {
            std::cout << "Option:\n";
            std::cin >> option;
            switch (option) {
                case 0:
                    return false;
                case 1:
                    std::cout << "\nGeben Sie eine Genre ein: ";
                    std::cin >> genre;
                    filme=ben->view_genre(genre);
                    valid();
                    if(filme.empty()) {
                        bool placut = false;
                        for (auto &iter : adm->view_filme()) {
                            cout << iter.anschreiben();
                            ShellExecute(NULL, "open", iter.gettrailer().c_str(), NULL, NULL, SW_SHOWNORMAL);
                            cout << "Hat es Ihnen den Trailer gefallen? 1 fur Ja, 0 fur nein";
                            int var ;
                            cin >> var;
                            if (var == 1)
                                placut = true;
                            if (placut) {
                                bool adaug = false;
                                cout << "Mochten Sie den Film zur Watchliste einfugen? 1 fur Ja, 0 fur nein";
                                cin >> var;
                                if (var == 1)
                                    adaug = true;
                                if (adaug)
                                    ben->addToWatchlist(iter);
                                break;
                            }

                        }
                    } else{
                        for (auto &it:filme) {
                        it.anschreiben();
                        }
                    }
                    break;
                case 2:
                    std::cout << "\nGeben Sie den Titel des Films ein, den Sie loschen mochten: ";
                    std::cin >> titel;
                    valid();
                    std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein, den Sie loschen mochten:  ";
                    std::cin >> jahr;
                    valid();
                    if(!ben->watch(titel, jahr))
                        cout<<"Sie haben keinen solchen Film in der Watchliste\n";
                    else{
                        cout << "Mochten Sie den Film bewerten? 1 fur Ja, 0 fur nein";
                        int var;bool like=false;
                        cin >> var;
                        if (var == 1)
                            like = true;
                        if (like) {
                            auto it = find_if(adm->view_filme().begin(), adm->view_filme().end(), [=](const Film& obj) {
                                return (obj.gettitel() == titel && obj.getjahr() == jahr);
                            });
                            if (it != adm->view_filme().end()) {
                                int index = std::distance(adm->view_filme().begin(), it);
                                adm->view_filme()[index].setlikes(adm->view_filme()[index].getlikes() + 1);
                            }
                        }
                    }
                    break;

                default:
                    break;

            }
        }
    }

}