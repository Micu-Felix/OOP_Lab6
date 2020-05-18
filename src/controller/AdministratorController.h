//
// Created by holom on 10.04.2020.
//
#pragma once

#include "../repository/FilmRepository.h"
#include "../domain/Film.h"
#include "../repository/RepositoryInMemory.cpp"
#include "../repository/FilmFileRepository.cpp"
class AdministratorController {
private:
    FilmRepository* repo;
public:
    AdministratorController();
    int size() { return repo->size(); };
    /**
     * RETURN THE FILM LIST
     */
    vector<Film> view_filme();

    bool add_film(const Film &film);
    bool delete_film(const string &titel, int jahr);
    bool edit_film(const string &titel, int jahr, string new_link);

};


