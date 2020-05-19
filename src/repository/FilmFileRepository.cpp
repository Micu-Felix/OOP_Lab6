
#pragma once
#include <fstream>
#include "FilmRepository.h"
#include <sstream>
#include <iostream>
#include "../exceptions/exceptions.cpp"

class FilmFileRepository : public FilmRepository {
private:
    string fileName;

    static Film split(const string &line, char delimiter) {
        string buffer;
        string result[5];
        int size = 0;
        for (char c : line) {
            if (c != delimiter) {
                buffer += c;
            } else if (!buffer.empty()) {
                result[size++] = buffer;
                buffer = "";
            }
        }
        if (!buffer.empty()) {
            result[size++] = buffer;
        }
        stringstream jahrString(result[2]);
        int jahr = 0;
        jahrString >> jahr;
        stringstream likesString(result[3]);
        int likes = 0;
        likesString >> likes;
        return Film(result[0], result[1], jahr, likes, result[4]);
    }

public:
    explicit FilmFileRepository(const string &fileName) : FilmRepository() {
        ifstream file(fileName);
        //fstream file(this->fileName);
        //file.open(fileName, ios::in);
        if (!file.is_open()) {
            throw FileNotFoundException(fileName);
        }
        file.close();
        this->fileName = fileName;
    }

    bool add_film(const Film &film) override {
        ofstream file(this->fileName, std::ios_base::app);
        file << '\n' << film.gettitel() << ',' << film.getgenre() << ',' << film.getjahr() << ',' << film.getlikes()
             << ',' << film.gettrailer();
        file.close();
        return true;
    }

    bool edit_film(const string &titel, int jahr, string new_link) override {
        ifstream file(this->fileName);
        vector<Film> filme = {};
        string line;
        if (!file.is_open()) {
            return false;
        }
        while (getline(file, line)) {
            Film film = split(line, ',');
            if (film.gettitel() == titel && film.getjahr() == jahr) {
                film.settrailer(new_link);
            }
            filme.push_back(film);
        }
        file.close();
        auto film = filme.begin();
        ofstream file2(fileName);
        file2 << "";
        file2.close();
        ofstream file3(fileName,ios_base::app);
        for (auto &film:filme){
            file3 << film.gettitel() << ',' << film.getgenre() << ',' << film.getjahr() << ',' << film.getlikes()
                 << ',' << film.gettrailer() << '\n';}
        file3.close();
        return true;
    }

    bool delete_film(const string &titel, int jahr) override {
        ifstream file(this->fileName);
        vector<Film> filme = {};
        string line;
        if (!file.is_open()) {
            return false;
        }
        while (getline(file, line)) {
            Film film = split(line, ',');
            if (film.gettitel() != titel || film.getjahr() != jahr) {
                filme.push_back(film);
            }
        }
        file.close();
        auto film = filme.begin();
        ofstream file2(fileName);
        file2 << "";
        file2.close();
        ofstream file3(fileName,ios_base::app);
        for (auto &film:filme){
            file3 << film.gettitel() << ',' << film.getgenre() << ',' << film.getjahr() << ',' << film.getlikes()
                  << ',' << film.gettrailer() << '\n';}
        file3.close();
        return true;
    }

    vector<Film> get_all() override {
        ifstream file(this->fileName);
        vector<Film> filme = {};
        string line;
        if (!file.is_open()) {
            return filme;
        }
        while (getline(file, line)) {
            Film film = split(line, ',');
            filme.emplace_back(film);
        }
        file.close();
        return filme;
    }
    int size()override {return 0;}
};