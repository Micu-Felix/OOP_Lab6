//
// Created by holom on 10.04.2020.
//
#pragma once
#ifndef LAB5_BENUTZER_H
#define LAB5_BENUTZER_H

#include "Film.h"
#include <vector>
#include "Repository.h"

class Benutzer {
    vector<Film> watchlist;
    Repository repo;
public:
    int size(){ return watchlist.size();};

    void view_genre(const string &genre);

    void watch(const string &titel, int jahr);
};


#endif //LAB5_BENUTZER_H
