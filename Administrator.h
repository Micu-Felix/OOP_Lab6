//
// Created by holom on 10.04.2020.
//
#pragma once
#ifndef LAB5_ADMINISTRATOR_H
#define LAB5_ADMINISTRATOR_H

#include "Repository.h"

class Administrator {
private:
    Repository repo;
public:
    int size(){ return repo.size();};
    /**
     * ADDS a FILM
     * @param film
     */
    void add_film(const Film& film);
    /**
     * SHOW THE FILM LIST
     */
    void view_filme();

    /**
     * DELETE A FILM
     * @param titel
     * @param jahr
     */
    void delete_film(const string& titel, int jahr);

    /**
     * EDIT THE LINK OF A MOVIE
     * @param titel
     * @param jahr
     * @param new_link
     */
    void edit_film(const string &titel, int jahr, string new_link);
};


#endif //LAB5_ADMINISTRATOR_H
