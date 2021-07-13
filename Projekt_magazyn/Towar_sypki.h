//
// Created by £ukasz on 25.02.2021.
//

#ifndef PROJEKT_MAGAZYN_TOWAR_SYPKI_H
#define PROJEKT_MAGAZYN_TOWAR_SYPKI_H

#include <utility>

#include "Produkt.h"


class Towar_sypki: public Produkt {
    float _waga_kg;
    int _typ = 2;
public:
    Towar_sypki( int id, std::string nazwa,float waga_kg = 0) : Produkt(id,std::move(nazwa),_typ,waga_kg),_waga_kg(waga_kg){};

    float pobierzIlosc()  override { return _waga_kg; };
    int pobierzTyp()  override {return _typ;};

    void dodaj(float &n) override;
    void odejmij(float &n) override;

    //Towar_sypki &operator+=(float n);                                                                           //operatory
    //Towar_sypki &operator-=(float n);
};



#endif //PROJEKT_MAGAZYN_TOWAR_SYPKI_H
