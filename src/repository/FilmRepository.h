//
// Created by holom on 10.04.2020.
//
#pragma once

#include "../domain/Film.h"
#include <vector>

/**
 * RepositoryInMemory
 */
class FilmRepository {

public:

    virtual bool add_film(const Film &film) = 0;

    /**
     * DELETE A FILM
     * @param titel
     * @param jahr
     */
    virtual bool delete_film(const string &titel, int jahr) = 0;

    /**
     * EDIT THE LINK OF A MOVIE
     * @param titel
     * @param jahr
     * @param new_link
     */
    virtual bool edit_film(const string &titel, int jahr, string new_link) = 0;

    virtual vector<Film> get_all() = 0;

    virtual int size()=0;
};



