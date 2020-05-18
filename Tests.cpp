//
// Created by Bond on 4/11/2020.
//
#include "Repository.h"
#include "BenutzerController.h"
#include "AdministratorController.h"
#include <assert.h>
#include <iostream>

void TestRepo() {
    Repository fel;
    assert(fel.size() == 10);
    auto vect = fel.get_all();
    assert(!vect.empty());

}

void TestBen() {
    BenutzerController ben;
    vector<Film> vect = ben.view_genre("sadic");
    assert(!vect.empty());
    vect = ben.view_genre("ornitorinc");
    assert(vect.empty());
    assert(ben.size() == 0);
    assert(!ben.watch("Q1", 1970));


}

void TestAdm() {
    Film film("T11", "orice", 1970, 110, "www.facebook.com");
    AdministratorController cori;
    assert(cori.size() == 10);
    assert(cori.add_film(film));
    assert(!cori.add_film(film));
    assert(cori.size() == 11);
    film.setjahr(1971);
    cori.add_film(film);
    assert(cori.size() == 12);
    assert(cori.delete_film("T11", 1971));
    assert(!cori.delete_film("T11", 1971));
    assert(cori.size() == 11);
    assert(cori.edit_film("T1", 1970, "www.google.ro"));
    assert(!cori.edit_film("B1", 1970, "www.google.ro"));
}


void TestFilm(){
    Film film("T11", "orice", 1970, 110, "www.facebook.com");
    assert(film.getjahr()==1970);
    assert(film.gettitel()=="T11");
    assert(film.getgenre()=="orice");
    assert(film.getlikes()==110);
    assert(film.gettrailer()=="www.facebook.com");
    film.setjahr(1971);
    assert(film.getjahr()==1971);
    film.setgenre("oric");
    assert(film.getgenre()=="oric");
    film.settitel("T111");
    assert(film.gettitel()=="T111");
    film.setlikes(12);
    assert(film.getlikes()==12);
    film.settrailer("www.google.de");
    assert(film.gettrailer()=="www.google.de");
}

void Teste() {
    std::cout << "\nTest START\n";

    TestFilm();
    TestAdm();
    TestRepo();
    TestBen();

    std::cout << "\nTest END\n\n";


}
