//
// Created by £ukasz on 25.02.2021.
//

#include "Paleciak.h"
#include <iostream>
float  Paleciak::_udzwig{0};
void Paleciak::dodaj_obiekt_na_paleciak(Produkt* p) {                                                               //metoda odpowiedzialna za dodawanie nowego towaru do wekotra klasy magazyn
    _paleciak.push_back(p);
    _udzwig+=p->pobierzWageCalkowita();
}
void Paleciak::wyswietl() const {   // wyœwietlanie klasy magazyn
    std::cout<<"------------------------------------Paleciak------------------------------------------\n";
    for(int i = 0; i < _paleciak.size(); i++) {
        std::cout <<"ID: "<<_paleciak[i]->pobierzID()<<"\tTyp: "<< _paleciak[i]->pobierzTyp()<<"\tNazwa: "<<_paleciak[i]->pobierzNazwa();
        if (_paleciak[i]->pobierzTyp() == 1)
            std::cout << "\tIlosc " << _paleciak[i]->pobierzIlosc()<<" szt.";                                                                         //uzycie zaprzyjaznionej metody <<  ktora znajduje sie w klasie Towar
        if (_paleciak[i]->pobierzTyp() == 2)
            std::cout << "\tIlosc " << _paleciak[i]->pobierzIlosc() << " kg";
        if (_paleciak[i]->pobierzTyp() == 3)
            std::cout << "\tIlosc " << _paleciak[i]->pobierzIlosc() << " l";
        std::cout<<"\tCalkowita waga "<<_paleciak[i]->pobierzWageCalkowita()<< " kg" <<std::endl;
    }
    std::cout<<"--------------------------------------------------------------------------------------\n";
    std::cout<<"Aktualny udzwig wynosi: "<<_udzwig<<std::endl;
    std::cout<<"--------------------------------------------------------------------------------------\n";
}
void Paleciak::usuwanie(int &numer_id) {

    _udzwig=_udzwig-_paleciak[znajdz_numer(numer_id)]->pobierzWageCalkowita();
    _paleciak.erase(_paleciak.begin()+znajdz_numer(numer_id));

}

int Paleciak::znajdz_numer(int &id) const {
    int znalezione_id;
    for (int i = 0; i < _paleciak.size(); ++i)
    {
        if(id == _paleciak[i]->pobierzID())
            znalezione_id = i;
    }
    return znalezione_id;
}


bool Paleciak::sprawdzanie(int &id)
{
    for (int i = 0; i < _paleciak.size(); ++i)
    {
        if(id == _paleciak[i]->pobierzID())
            return false;
    }

    return true;
}
bool Paleciak::sprawdzanie( int &id, float &ilosc)const {//funkcja sprawdzajaca czy wybranego przez uzytkownika towaru jest wystarczajaca ilosc by mozna by³o od niej odj¹æ liczbe podana przez uzytkownika

    if(ilosc <= _paleciak[znajdz_numer(id)]->pobierzIlosc()&& ilosc >= 0)
        return false;
    if (ilosc<0) {
        std::cout << "Nie mozesz odjac ujemnej liczby\n";
        return true;
    }
    else
    {
        std::cout << "Nie ma wystarczajaco sztuk w magazynie.\nAktualna ilosc produktu\"" << _paleciak[znajdz_numer(id)]->pobierzNazwa() << "\" wynosi: " << _paleciak[znajdz_numer(id)]->pobierzIlosc() << std::endl;
        return true;
    }
}

Produkt* Paleciak::pobierzProdukt(int &id)
{

    return _paleciak[znajdz_numer(id)];
}
/*void Paleciak::dodanie_po_podziel(Towar *t)
{
    _paleciak.push_back(t);
}*/
/*bool Paleciak::sprawdzanieTypu(int id,int id2)
{
    if(_paleciak[id]->pobierzTyp()==_paleciak[id2]->pobierzTyp()==1)
        return false;
    return true;
}*/
/*void Paleciak::wydaj(std::vector<Produkt*> t, int numer)
{
    int znalezione_id;
    for (int i = 0; i < t.size(); ++i) {
        if(numer == t[i]->pobierzID())
            znalezione_id = i;
    }
    _udzwig=_udzwig+t[znalezione_id]->pobierzIlosc();
    _paleciak.push_back(t[znalezione_id]);
}*/