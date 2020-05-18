//
// Created by holom on 10.04.2020.
//
#pragma once
#ifndef LAB5_ADMINISTRATOR_H
#define LAB5_ADMINISTRATOR_H

#include "Repository.h"

class AdministratorController {
private:
    Repository repo;
public:
    int size() { return repo.size(); };
    /**
     * RETURN THE FILM LIST
     */
    vector<Film> view_filme();

    bool add_film(const Film &film);
    bool delete_film(const string &titel, int jahr);
    bool edit_film(const string &titel, int jahr, string new_link);

};


#endif //LAB5_ADMINISTRATOR_H
