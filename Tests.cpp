//
// Created by Bond on 4/11/2020.
//
#include "Repository.h"
#include "Benutzer.h"
#include "Administrator.h"
#include <assert.h>
#include <iostream>

void Teste() {
    std::cout << "\nTest START\n\n";
    Film film("T11", "orice", 1970, 110, "www.facebook.com");
    Repository fel;
    assert(fel.size() == 10);
    Administrator cori;
    assert(cori.size() == 10);
    cori.add_film(film);
    assert(cori.size() == 11);
    film.setjahr(1971);
    cori.add_film(film);
    assert(cori.size() == 12);
    cori.delete_film("T11", 1971);
    assert(cori.size() == 11);
    std::cout << "\nTest END\n\n";


}
