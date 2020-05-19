//
// Created by holom on 19.05.2020.
//

#include "BenutzerController.h"
#include <algorithm>
#include <windows.h>
#include <shellapi.h>
#include <iostream>
#include <windows.h>
 //namespace fs = std::filesystem;
vector<Film> BenutzerController::view_genre(const string &genre) {
    vector<Film> aux = {};
    for (auto &iter : repo->get_all()) {
        if (iter.getgenre() == genre) {
            aux.push_back(iter);
        }
    }
    return aux;
}

static Film split(const string &line, char delimiter) {
    string buffer;
    string result[5];
    int size = 0;
    for (char c : line) {
        if (c != delimiter) {
            buffer += c;
        } else if (!buffer.empty()) {
            result[size++] = buffer;
            buffer = "";
        }
    }
    if (!buffer.empty()) {
        result[size++] = buffer;
    }
    stringstream jahrString(result[2]);
    int jahr = 0;
    jahrString >> jahr;
    stringstream likesString(result[3]);
    int likes = 0;
    likesString >> likes;
    return Film(result[0], result[1], jahr, likes, result[4]);
}

bool BenutzerController::watch(const string &titel, int jahr) {
    watchlist = get_all_watch();
    auto it = find_if(watchlist.begin(), watchlist.end(), [=](const Film &obj) {
        return (obj.gettitel() == titel && obj.getjahr() == jahr);
    });
    if (it != watchlist.end()) {
        watchlist.erase(it);
        if (format == "resources/watchlist.csv") {
            string fileName = format;
            ifstream file(fileName);
            vector<Film> filme = {};
            string line;
            if (!file.is_open()) {
                return false;
            }
            while (getline(file, line)) {
                Film film = split(line, ',');
                if (film.gettitel() != titel || film.getjahr() != jahr) {
                    filme.push_back(film);
                }
            }
            file.close();
            //auto film = filme.begin();
            ofstream file2(fileName);
            file2 << "";
            file2.close();
            ofstream file3(fileName, ios_base::app);
            for (auto &film:filme) {
                file3 << film.gettitel() << ',' << film.getgenre() << ',' << film.getjahr() << ',' << film.getlikes()
                      << ',' << film.gettrailer() << '\n';
            }
            file3.close();

            return true;
        }
    } else {
        cout << "am intrat pe false\n";
        return false;
    }
    return true;
}

BenutzerController::BenutzerController() {
    this->repo = new FilmFileRepository{"resources/filme.csv"};
    ofstream file("resources/watchlist.html", ios_base::app);
    file.close();
    ofstream file1("resources/watchlist.csv", ios_base::app);
    file1.close();

}

void BenutzerController::addToWatchlist(const Film &film) {
    watchlist.push_back(film);
    ofstream file(format, ios_base::app);
    file << film.gettitel() << ',' << film.getgenre() << ',' << film.getjahr() << ',' << film.getlikes()
         << ',' << film.gettrailer() << '\n';
    file.close();
}

vector<Film> BenutzerController::get_all_watch() {
    if (format == "resources/watchlist.csv") {

        ifstream file(format);
        vector<Film> filme = {};
        string line;
        if (!file.is_open()) {
            return filme;
        }
        while (getline(file, line)) {
            Film film = split(line, ',');
            cout << film.gettitel() << '\n';
            filme.push_back(film);
        }
        file.close();
        return filme;
    }
}
void BenutzerController::view() {

    std::cout<< "Current path is " <<ExePath() << '\n';
    string path=ExePath();

    if (format == "resources/watchlist.csv") {
        path+="\\resources\\watchlist.csv";
        cout<<"path este: "<<path<<'\n';
        ShellExecute(NULL, "open", path.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }else {
        path+="\\resources\\watchlist.html";
        ShellExecute(NULL, "open", R"(D:\Facultate\OOP\Git\OOP_Lab6\cmake-build-debug\resources\watchlist.html)", NULL,
                     NULL, SW_SHOWNORMAL);
    }
}

string BenutzerController::ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}
