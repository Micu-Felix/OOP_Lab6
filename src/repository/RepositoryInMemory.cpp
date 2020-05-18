//
// Created by Bond on 5/17/2020.
//
#include "FilmRepository.h"
#include <algorithm>
#pragma once
class RepositoryInMemory : public FilmRepository {
private:
    vector<Film> repository;
public:
    RepositoryInMemory() : FilmRepository() {
        repository = {Film("T1", "sadic", 1970, 100, "https://ro.wikipedia.org/wiki/Raton"),
                      Film("T2", "action", 1970, 100,
                           "https://www.google.com/search?q=made_by_felix%26corina&oq=made_by_felix%26corina&aqs=chrome..69i57.13080j0j4&sourceid=chrome&ie=UTF-8"),
                      Film("T3", "comedy", 1970, 100,
                           "https://www.google.com/search?q=made_by_felix%26corina&oq=made_by_felix%26corina&aqs=chrome..69i57.13080j0j4&sourceid=chrome&ie=UTF-8"),
                      Film("T4", "action", 1970, 100,
                           "https://www.google.com/search?q=made_by_felix%26corina&oq=made_by_felix%26corina&aqs=chrome..69i57.13080j0j4&sourceid=chrome&ie=UTF-8"),
                      Film("T5", "action", 1970, 100,
                           "https://www.google.com/search?q=made_by_felix%26corina&oq=made_by_felix%26corina&aqs=chrome..69i57.13080j0j4&sourceid=chrome&ie=UTF-8"),
                      Film("T7", "action", 1970, 100,
                           "https://www.google.com/search?q=made_by_felix%26corina&oq=made_by_felix%26corina&aqs=chrome..69i57.13080j0j4&sourceid=chrome&ie=UTF-8"),
                      Film("T8", "action", 1970, 100,
                           "https://www.google.com/search?q=made_by_felix%26corina&oq=made_by_felix%26corina&aqs=chrome..69i57.13080j0j4&sourceid=chrome&ie=UTF-8"),
                      Film("T6", "action", 1970, 100,
                           "https://www.google.com/search?q=made_by_felix%26corina&oq=made_by_felix%26corina&aqs=chrome..69i57.13080j0j4&sourceid=chrome&ie=UTF-8"),
                      Film("T9", "action", 1970, 100,
                           "https://www.google.com/search?q=made_by_felix%26corina&oq=made_by_felix%26corina&aqs=chrome..69i57.13080j0j4&sourceid=chrome&ie=UTF-8"),
                      Film("T10", "action", 1970, 100, "https://ro.wikipedia.org/wiki/Raton"),

        };
    };

    int size() override { return repository.size(); };

    bool delete_film(const string &titel, int jahr) override {
        auto endv_med = std::remove_if(begin(repository), end(repository), [=](const Film &film) {
            return ((film.gettitel() == titel) && (film.getjahr() == jahr));
        });
        if (endv_med != end(repository)) {
            repository.erase(endv_med, end(repository));
            return true;
        } else
            return false;


    }

    bool add_film(const Film &film) override {
        auto it = find_if(repository.begin(), repository.end(), [=](const Film &obj) {
            return (obj.gettitel() == film.gettitel() && obj.getjahr() == film.getjahr());
        });
        if (it != repository.end()) {
            return false;
        } else {
            repository.push_back(film);
            return true;
        }
    }

    bool edit_film(const string &titel, int jahr, string new_link) override {
        auto it = find_if(repository.begin(), repository.end(), [=](const Film &obj) {
            return (obj.gettitel() == titel && obj.getjahr() == jahr);
        });
        if (it != repository.end()) {
            int index = std::distance(repository.begin(), it);
            repository[index].settrailer(std::move(new_link));
            return true;
        } else {
            return false;
        }
    }

    vector<Film> get_all()override {
        return repository;
    }
};