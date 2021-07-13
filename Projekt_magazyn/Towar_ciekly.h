//
// Created by £ukasz on 25.02.2021.
//

#ifndef PROJEKT_MAGAZYN_TOWAR_CIEKLY_H
#define PROJEKT_MAGAZYN_TOWAR_CIEKLY_H

#include <utility>

#include "Produkt.h"

class Towar_ciekly : public Produkt {
    float _waga_l;
    int _typ = 3;
public:
    Towar_ciekly( int id, std::string nazwa, float waga_l = 0) : Produkt(id,std::move(nazwa),_typ,waga_l),_waga_l(waga_l){};


    float pobierzIlosc()  override { return _waga_l; };
    int pobierzTyp()  override{return _typ;};


    void dodaj(float &n) override;
    void odejmij(float &n) override;

    //Towar_ciekly &operator+=(float n);                                                                           //operatory
   // Towar_ciekly &operator-=(float n);
};



#endif //PROJEKT_MAGAZYN_TOWAR_CIEKLY_H
