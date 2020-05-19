//
// Created by holom on 19.05.2020.
//

#include "BenutzerController.h"
#include <algorithm>

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
    auto it = find_if(watchlist.begin(), watchlist.end(), [=](const Film &obj) {
        return (obj.gettitel() == titel && obj.getjahr() == jahr);
    });
    if (it != watchlist.end()) {
        string fileName="watchlist"+format;
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
        auto film = filme.begin();
        ofstream file2(fileName);
        file2 << "";
        file2.close();
        ofstream file3(fileName,ios_base::app);
        for (auto &film:filme){
            file3 << film.gettitel() << ',' << film.getgenre() << ',' << film.getjahr() << ',' << film.getlikes()
                  << ',' << film.gettrailer() << '\n';}
        file3.close();
        watchlist.erase(it);
        return true;
    } else {
        return false;
    }
}

BenutzerController::BenutzerController() {
    this->repo=new FilmFileRepository{"resources/filme.csv"};
}

