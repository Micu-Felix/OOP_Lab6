#include "iostream"
#include "FilmUI.h"
#include <windows.h>
#include <shellapi.h>
#include "../validation/validation.h"
using namespace std;


FilmUI::FilmUI() {
    try {
        this->adm = new AdministratorController{};
        this->ben = new BenutzerController{};
    } catch (FileNotFoundException &e) {
        cout << e.what() << endl;
        throw;
    }

}

void FilmUI::show_menu(int modus) {

    cout << menu(modus);
}

void FilmUI::startUI() {
    int modus;
    std::cout
            << "In welchen Modus mochten sie das Programm starten? 1 fur Adminstr. oder 2 fur BenutzerController: ?????\n\n";
    std::cin >> modus;
    switch (modus) {
        case 1:
            AdministratorUI();
            break;
        case 2:
            BenutzerUI();
            break;
        default:
            cout<<"Es git diesen Modus nicht!!\n";
            break;
    }
}

void FilmUI::AdministratorUI() {
    show_menu(1);
    int option;
    std::string titel, genre, trailer;
    int jahr, likes;
    std::string new_link;
    bool ok=true;
    while (ok) {
        std::cout << "Option:\n";
        std::cin >> option;
        switch (option) {
            case 0:
                ok=false;
                break;
            case 1:
                std::cout << "\nGeben Sie den Titel des Films ein: ";
                std::cin >> titel;
                std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein: ";
                std::cin >> jahr;
                std::cout << "\nGeben Sie das Genre des Films ein: ";
                std::cin >> genre;
                try {
                    std::cout << "\nGeben Sie den Link des Trailes des Films ein: ";
                    std::cin >> trailer;
                    Valid::checkTrailer(trailer);
                }catch (const char* str){
                    std::cout << str << '\n';
                    break;
                }
                std::cout << "\nGeben Sie die Anzahl von Likes des Films ein: ";
                try {
                    std::cin >> likes;
                    std::cin.get();
                    Valid::checkFilmLikes(likes);
                }
                catch (std::out_of_range()){
                    std::cout << "Numar invalid\n";
                    break;
                }
                if (!adm->add_film(Film(titel, genre, jahr, likes, trailer)))
                    std::cout << "Es gibt schon diesen Film\n";
                else
                    cout << "Film wurde eingefugt !!\n";

                break;
            case 2:
                std::cout << "\nGeben Sie den Titel des Films ein, den Sie bearbeiten mochten: ";
                std::cin >> titel;
                std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein, den Sie bearbeiten mochten:  ";
                std::cin >> jahr;
                try {
                    std::cout << "\nGeben Sie den neuen Link des Films ein:  ";
                    std::cin >> new_link;
                    Valid::checkTrailer(new_link);
                }catch (const char* str){
                    std::cout << str << '\n';
                    break;
                }
                if (!adm->edit_film(titel, jahr, new_link))
                    std::cout << "Es gibt keine solchen Film\n";
                else
                    cout << "Erfolgreiche Bearbeitung der Daten !!\n";
                break;
            case 3:

                std::cout << "\nGeben Sie den Titel des Films ein, den Sie loschen mochten: ";
                std::cin >> titel;
                std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein, den Sie loschen mochten:  ";
                std::cin >> jahr;
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
                break;
            default:
                break;

        }
    }

}

void FilmUI::BenutzerUI() {
    show_menu(2);
    vector<Film> filme;
    int option;
    std::string titel, genre, trailer;
    int jahr,format;
    std::string new_link;
    std::cout
            << "0 fur CSV und 1 fur HTML\n\n";
    std::cin >> format;
    switch (format) {
        case 0:
            ben->formatsetter(".csv");
            break;
        case 1:
            ben->formatsetter(".html");
            break;
        default:
            cout<<"Es git diesen Modus nicht!!\n";
            break;
    }
    bool ok=true;
    while (ok) {
        std::cout << "Option:\n";
        std::cin >> option;
        switch (option) {
            case 0:
                ok=false;
                break;
            case 1:
                std::cout << "\nGeben Sie eine Genre ein: ";
                std::cin >> genre;
                filme = ben->view_genre(genre);
                if (filme.empty()) {
                    bool placut = false;
                    for (auto &iter : adm->view_filme()) {
                        cout << iter.anschreiben();
                        ShellExecute(NULL, "open", iter.gettrailer().c_str(), NULL, NULL, SW_SHOWNORMAL);
                        cout << "Hat es Ihnen den Trailer gefallen? 1 fur Ja, 0 fur nein";
                        int var;
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
                } else {
                    for (auto &it:filme) {
                        it.anschreiben();
                    }
                }
                break;
            case 2:
                std::cout << "\nGeben Sie den Titel des Films ein, den Sie loschen mochten: ";
                std::cin >> titel;
                std::cout << "\nGeben Sie das Erscheinungsjahr des Films ein, den Sie loschen mochten:  ";
                std::cin >> jahr;
                std::cout << "\nGeben Sie den neuen Link des Films ein:  ";
                try {
                    Valid::checkFilmExists(adm->view_filme(),titel,jahr);
                }catch (FilmNotFoundException &e){
                    std::cout << "Film Not Found" << '\n';
                    break;
                }
                //if (!ben->watch(titel, jahr))
                //    cout << "Sie haben keinen solchen Film in der Watchliste\n";
                //else {
                if(ben->watch(titel, jahr)){
                    cout << "Mochten Sie den Film bewerten? 1 fur Ja, 0 fur nein";
                    int var;
                    bool like = false;
                    cin >> var;
                    if (var == 1)
                        like = true;
                    if (like) {
                        auto it = find_if(adm->view_filme().begin(), adm->view_filme().end(), [=](const Film &obj) {
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

std::string FilmUI::menu(int modus) {
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
