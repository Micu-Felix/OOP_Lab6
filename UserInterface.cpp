//
// Created by Bond on 4/10/2020.
//
#include <string>
#include <iostream>
#include "Administrator.h"
#include "Benutzer.h"
#include <stdlib.h>
#include <typeinfo>

std::string menu(int modus) {
    std::string aux;
    if (modus == 1)
        aux = "\nMenu Administrator :-)\n"
              "Wahlen Sie eine Option: \n"
              "1 - Einfugen\n"
              "2 - Bearbeitung der Daten\n"
              "3 - Loschen\n"
              "4 - Liste Filme ansehen\n"
              "0 - Exit\n"
              "\n";
    else
        aux = "\nMenu Benutzer :-)\n"
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
    std::cout << "In welchen Modus mochten sie das Programm starten? 1 fur Adminstr. oder 2 fur Benutzer: ?????\n";
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
    if (modus == 1) {
        auto adm = new Administrator();
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
                    adm->add_film(Film(titel, genre, jahr, likes, trailer));
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
                    adm->edit_film(titel, jahr, new_link);
                    break;
                case 3:

                    std::cout << "\nGeben Sie den Titel des Films ein, den Sie loschen mochten: ";
                    std::cin >> titel;
                    valid();
                    std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein, den Sie loschen mochten:  ";
                    std::cin >> jahr;
                    valid();
                    adm->delete_film(titel, jahr);
                    break;
                case 4:
                    adm->view_filme();
                default:
                    break;

            }
        }
    } else {
        auto ben = new Benutzer();
        while (true) {
            std::cout << "Option:\n";
            std::cin >> option;
            switch (option) {
                case 0:
                    return false;
                case 1:
                    std::cout << "\nGeben Sie eine Genre ein: ";
                    std::cin >> genre;
                    valid();
                    ben->view_genre(genre);
                    break;
                case 2:
                    std::cout << "\nGeben Sie den Titel des Films ein, den Sie loschen mochten: ";
                    std::cin >> titel;
                    valid();
                    std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein, den Sie loschen mochten:  ";
                    std::cin >> jahr;
                    valid();
                    ben->watch(titel, jahr);
                    break;

                default:
                    break;

            }
        }
    }

}