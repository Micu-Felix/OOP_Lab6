#pragma once

#include <string>
#include <utility>

using namespace std;

class Film {
private:
    string titel, genre, trailer;
    int jahr, likes;
public:
    Film(string titel, string genre, int jahr, int likes, string trailer) {
        settitel(std::move(titel));
        setgenre(std::move(genre));
        setjahr(jahr);
        setlikes(likes);
        settrailer(std::move(trailer));
    };

/**
 *
 * GETTERS AND SETTERS
 *
 */
    void settitel(string value) { titel = std::move(value); };

    [[nodiscard]] string gettitel() const { return titel; };


    void setgenre(string value) { genre = std::move(value); };

    [[nodiscard]] string getgenre() const { return genre; };


    void settrailer(string value) { trailer = std::move(value); };

    [[nodiscard]] string gettrailer() const { return trailer; };

    void setjahr(int value) { jahr = value; };

    [[nodiscard]] int getjahr() const { return jahr; };

    void setlikes(int value) { likes = value; };

    [[nodiscard]] int getlikes() const { return likes; };

    string anschreiben() const {
        return "Der Film mit dem Namen: " + gettitel() + " in dem Jahr " + to_string(getjahr()) + " " +
               " und hat folgendes Genre:" + getgenre() +
               " und hat so viele Likes: " + to_string(getlikes()) + "\n";
    };

};


