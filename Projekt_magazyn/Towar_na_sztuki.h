//
// Created by £ukasz on 25.02.2021.
//

#ifndef PROJEKT_MAGAZYN_TOWAR_NA_SZTUKI_H
#define PROJEKT_MAGAZYN_TOWAR_NA_SZTUKI_H

#include <utility>

#include "Produkt.h"


class Towar_na_sztuki: public Produkt {

    float _ilosc;
    int _typ = 1;
    float _waga_sztuki;


public:
    Towar_na_sztuki( int id, std::string nazwa,float waga_sztuki =0, float ilosc = 0 ,float waga_calego_towaru = 0) : Produkt(id,std::move(nazwa),_typ,waga_calego_towaru),_ilosc(ilosc),_waga_sztuki(waga_sztuki){};          //Konstruktor

    //metody zwracajace zmienne prywatne
    float pobierzIlosc()  override { return _ilosc; };
    int pobierzTyp()  override {return _typ;};


    void dodaj(float &n) override;
    void odejmij(float &n) override;

    //friend std::ostream& operator<<(std::ostream&,const Towar_na_sztuki&);//zaprzyjanienie znaku wypisania <<
    //Towar_na_sztuki &operator+=(int n);                                                                           //operatory
    //Towar_na_sztuki &operator-=(int n);

    //Towar_na_sztuki* podziel(int id,Towar_na_sztuki* t, int nowa_ilosc);
    //void scal(Towar_na_sztuki* t,Towar_na_sztuki* t2);
};


#endif //PROJEKT_MAGAZYN_TOWAR_NA_SZTUKI_H
