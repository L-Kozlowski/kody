//
// Created by £ukasz on 25.02.2021.
//

#ifndef PROJEKT_MAGAZYN_PALECIAK_H
#define PROJEKT_MAGAZYN_PALECIAK_H
#include <vector>
#include "Produkt.h"

class Paleciak {
protected:
    std::vector<Produkt*> _paleciak;              // tworzenie wektora
    static float _udzwig;

public:
    Paleciak() = default;
    void dodaj_obiekt_na_paleciak(Produkt* p);
    void wyswietl() const;
    void usuwanie(int &numer_id);
    int znajdz_numer(int &id) const;
    static void udzwig(){std::cout<<"Aktualny udzwig paleciaka wynosi: "<< _udzwig<<" kg"<<std::endl;}
    void dodaj_ilosc(int &id, float &ilosc){_paleciak[znajdz_numer(id)]->dodaj(ilosc); _udzwig=_udzwig+_paleciak[znajdz_numer(id)]->pobierzWageCalkowita();}
    void odejmij_ilosc(int &id, float &ilosc){_paleciak[znajdz_numer(id)]->odejmij(ilosc);_udzwig=_udzwig-_paleciak[znajdz_numer(id)]->pobierzWageCalkowita();}
    bool sprawdzanie(int &id);
    bool sprawdzanie( int &id, float &ilosc)const;
    float pobierzIlosc(int &id){return _paleciak[znajdz_numer(id)]->pobierzIlosc();}
    Produkt* pobierzProdukt(int &id);

    //std::vector<Produkt*> pobierzWektor(){return _paleciak;}
    //void wydaj(std::vector<Produkt*> t, int numer);
    //int pobierzTyp(int id){return _paleciak[id]->pobierzTyp();}
    //int pobierzWielkosc(){return _paleciak.size();}
    //bool sprawdzanieTypu(int id,int id2);
    //void dodanie_po_podziel(Towar *t);
    //void zwieksz_id();
    //int _wielkosc;                           //zmienna odpowiadajaca za pamietanie _wielkosc wektora

};
#endif //PROJEKT_MAGAZYN_PALECIAK_H
