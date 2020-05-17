//
// Created by holom on 10.04.2020.
//

#include "Benutzer.h"
#include <iostream>
#include <algorithm>

void Benutzer::view_genre(const string &genre) {
    bool gasit = false;
    for (auto &iter : repo.filme) {
        if (iter.getgenre() == genre) {
            gasit = true;
            cout << iter.anschreiben();
        }
    }
    if (!gasit) {
        bool placut = false;
        for (auto &iter : repo.filme) {
            cout << iter.anschreiben();
            //system(("open "s + iter.gettrailer()).c_str()); // c++
            system(("start " + iter.gettrailer()).c_str());
            cout << "Hat es Ihnen den Trailer gefallen? 1 fur Ja, 0 fur nein";
            int var = 0;
            cin >> var;
            if (var == 1)
                placut = true;
            if (placut) {
                bool adaug = false;
                cout << "Mochten Sie den Film zur Watchliste einfugen? 1 fur Ja, 0 fur nein";
                var = 0;
                cin >> var;
                if (var == 1)
                    adaug = true;
                if (adaug)
                    watchlist.push_back(iter);
                break;
            }

        }
    }
}

void Benutzer::watch(const string &titel, int jahr) {
    bool like = false;
    auto it = find_if(watchlist.begin(), watchlist.end(), [=](const Film& obj) {
        return (obj.gettitel() == titel && obj.getjahr() == jahr);
    });
    if (it != watchlist.end()) {
        watchlist.erase(it);
        cout << "Mochten Sie den Film bewerten? 1 fur Ja, 0 fur nein";
        int var;
        cin >> var;
        if (var == 1)
            like = true;

    } else{cout<<"Sie haben keinen solchen Film in der Watchliste\n";}
    if (like) {
        it = find_if(repo.filme.begin(), repo.filme.end(), [=](const Film& obj) {
            return (obj.gettitel() == titel && obj.getjahr() == jahr);
        });
        if (it != repo.filme.end()) {
            int index = std::distance(repo.filme.begin(), it);
            repo.filme[index].setlikes(repo.filme[index].getlikes() + 1);
        }
    }
}

