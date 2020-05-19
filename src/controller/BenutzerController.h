//
// Created by holom on 19.05.2020.
//

#pragma once

#include <utility>

#include "../repository/FilmRepository.h"
#include "../domain/Film.h"
#include "../repository/FilmInMemoryRepository.cpp"
#include "../repository/FilmFileRepository.cpp"

class BenutzerController {
    vector<Film> watchlist;
    FilmRepository* repo;
    string format="resources/watchlist";
    vector <Film> get_all_watch();
    string ExePath();
public:
    BenutzerController();

    void formatsetter(string value){format=std::move(value);}
    string formatgetter(){ return format;}
    int size(){ return watchlist.size();};

    vector<Film> view_genre(const string &genre);

    bool watch(const string &titel, int jahr);

    void addToWatchlist(const Film& film);

    void view();
    };