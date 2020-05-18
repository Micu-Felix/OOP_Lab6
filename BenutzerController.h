//
// Created by holom on 10.04.2020.
//
#pragma once
#ifndef LAB5_BENUTZER_H
#define LAB5_BENUTZER_H

#include "Film.h"
#include <vector>
#include "Repository.h"

class BenutzerController {
    vector<Film> watchlist;
    Repository repo;
public:
    int size(){ return watchlist.size();};

    vector<Film> view_genre(const string &genre);

    bool watch(const string &titel, int jahr);

    void addToWatchlist(const Film& film){
        watchlist.push_back(film);
    }
};


#endif //LAB5_BENUTZER_H
