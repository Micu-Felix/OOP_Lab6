//
// Created by holom on 10.04.2020.
//

#include "BenutzerController.h"
#include <algorithm>

vector<Film> BenutzerController::view_genre(const string &genre) {
    vector<Film> aux = {};
    for (auto &iter : repo.get_all()) {
        if (iter.getgenre() == genre) {
            aux.push_back(iter);
        }
    }
    return aux;
}

bool BenutzerController::watch(const string &titel, int jahr) {
    auto it = find_if(watchlist.begin(), watchlist.end(), [=](const Film &obj) {
        return (obj.gettitel() == titel && obj.getjahr() == jahr);
    });
    if (it != watchlist.end()) {
        watchlist.erase(it);
        return true;
    } else {
        return false;
    }
}

