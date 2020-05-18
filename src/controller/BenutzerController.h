//
// Created by holom on 10.04.2020.
//
#pragma once

#include "../repository/FilmRepository.h"
#include "../domain/Film.h"
#include "../repository/RepositoryInMemory.cpp"
#include "../repository/FilmFileRepository.cpp"

class BenutzerController {
    vector<Film> watchlist;
    FilmRepository* repo;
public:
    BenutzerController();
    int size(){ return watchlist.size();};

    vector<Film> view_genre(const string &genre);

    bool watch(const string &titel, int jahr);

    void addToWatchlist(const Film& film){
        watchlist.push_back(film);
    }
};



