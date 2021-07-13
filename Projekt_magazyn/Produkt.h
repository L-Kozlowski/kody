//
// Created by £ukasz on 25.02.2021.
//

#ifndef PROJEKT_MAGAZYN_PRODUKT_H
#define PROJEKT_MAGAZYN_PRODUKT_H

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Produkt {
protected:
    int _id;
    std::string _nazwa;
    int _typ;
    float _waga_calego_towaru;
public:
    Produkt(int id,std::string nazwa,int typ,float waga_calego_towaru):_id(id),_nazwa(std::move(nazwa)),_typ(typ),_waga_calego_towaru(waga_calego_towaru){}
    Produkt(){_id=0;_nazwa="";_typ=0;_waga_calego_towaru=0;};

    int pobierzID()  { return _id; };
    std::string pobierzNazwa()  { return _nazwa; };
    virtual float pobierzIlosc() { return 0;};
    virtual int pobierzTyp() {return _typ;};
    float pobierzWageCalkowita() { return _waga_calego_towaru;};

    virtual void dodaj(float &n) {};
    virtual void odejmij(float &n){};

    //void dodajWage(float n) {_waga_calego_towaru +=n; }
    //void kopiuj(Produkt* p){ _id = p->pobierzID();_nazwa = p->pobierzNazwa();_waga_calego_towaru= p->pobierzWageCalkowita();_typ = p->pobierzTyp(); };




};

#endif //PROJEKT_MAGAZYN_PRODUKT_H
