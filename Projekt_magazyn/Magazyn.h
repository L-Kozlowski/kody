//
// Created by £ukasz on 25.02.2021.
//

#ifndef PROJEKT_MAGAZYN_MAGAZYN_H
#define PROJEKT_MAGAZYN_MAGAZYN_H
#include <vector>
#include "Towar_na_sztuki.h"
#include "Towar_sypki.h"
#include "Towar_ciekly.h"
#include "Paleciak.h"

class Magazyn {
protected:
    std::vector<Produkt*> _towary;              // tworzenie wektora

public:

    Magazyn() = default;              //kostruktor z przypisaniem nowemu magzynowi _wielkosc 0

    //void dodaj(std::string &nazwa, int typ,int id,float ilosc,float waga);
    void dodaj(Produkt* p);
    void wyswietl() const;

    void przyjecie( int &id, float &ilosc);
    void odbior( int &id, float &ilosc);

    bool sprawdz()const;                    //przeladowanie funkcji sprawdz
    bool sprawdz(const int &id) const;
    bool sprawdz( int &id, float &ilosc) const;

    void usuwanie(int &numer);

    int znajdz_numer(int &id) const;
    int pobierzWielkosc(){return _towary.size();}
    float pobierzIlosc(int &id){return _towary[znajdz_numer(id)]->pobierzIlosc();}

    Produkt* pobierzProdukt(int &id);
   // std::vector<Produkt*> pobierzWektor2(){return _towary;}
    //void przyjmij(Paleciak p, int numer);

};


#endif //PROJEKT_MAGAZYN_MAGAZYN_H
