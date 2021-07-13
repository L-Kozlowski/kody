//
// Created by £ukasz on 25.02.2021.
//

#include "Magazyn.h"
#include <iostream>


void Magazyn::usuwanie(int &numer) {

    _towary.erase(_towary.begin()+znajdz_numer(numer));
}
/*void Magazyn::dodaj(std::string &nazwa, int typ,int _numer_id,float ilosc,float waga) {                                                               //metoda odpowiedzialna za dodawanie nowego towaru do wekotra klasy magazyn
    if(typ == 1)
        _towary.push_back(new Towar_na_sztuki(_numer_id,nazwa,ilosc,waga));
    if(typ== 2)
        _towary.push_back(new Towar_sypki(_numer_id,nazwa,waga));
    if(typ== 3)
        _towary.push_back(new Towar_ciekly(_numer_id,nazwa,waga));
    std::cout << "Dodales produkt \"" << nazwa << "\", ktorego ID wynosi: " << _numer_id << std::endl;
    //_numer_id++;
}*/
void Magazyn::dodaj(Produkt* produkt) {                                                               //metoda odpowiedzialna za dodawanie nowego towaru do wekotra klasy magazyn

        _towary.push_back(produkt);
}
void Magazyn::wyswietl() const {                                                                        // wyœwietlanie klasy magazyn
    for(int i = 0; i < _towary.size(); i++) {
        std::cout << "ID: " << _towary[i]->pobierzID() << "\tTyp: " << _towary[i]->pobierzTyp() << "\tNazwa: "<< _towary[i]->pobierzNazwa();
        if (_towary[i]->pobierzTyp() == 1)
            std::cout << "\tIlosc " << _towary[i]->pobierzIlosc()<<" szt.";                                                                         //uzycie zaprzyjaznionej metody <<  ktora znajduje sie w klasie Towar
        if (_towary[i]->pobierzTyp() == 2)
            std::cout << "\tIlosc " << _towary[i]->pobierzIlosc() << " kg";
        if (_towary[i]->pobierzTyp() == 3)
            std::cout << "\tIlosc " << _towary[i]->pobierzIlosc() << " l";
        std::cout<<"\tCalkowita waga "<<_towary[i]->pobierzWageCalkowita()<< " kg" <<std::endl;
    }
}

void Magazyn::przyjecie( int &id, float &ilosc) {//zmiana ilosci towaru, przekazane id towaru ktorego chcemy zmienic oraz o ile

    if(ilosc>=0)
        _towary[znajdz_numer(id)]->dodaj(ilosc);                                                                             //uzycie operatora dodawanie napisanego w klasie Towar
    else {
        std::cout<<"Nastapila zamiana ujemnej liczby na dodatnia i dodanie do magazynu Jesli chcesz odjac zawartosc uzyj funkcji odbior\n ";
        float ilosc2 = - ilosc;
        _towary[znajdz_numer(id)]->dodaj(ilosc2);
    }
    std::cout << "Ilosc produktu \"" << _towary[znajdz_numer(id)]->pobierzNazwa() << "\" zostala zmieniona na: " << _towary[znajdz_numer(id)]->pobierzIlosc() << std::endl;
}


void Magazyn::odbior( int &id, float &ilosc) {//analogicznie jak dla metody przyjecie, uzycie operatora odejmowanie z klasy Towar

    _towary[znajdz_numer(id)]->odejmij(ilosc);
    std::cout << "Ilosc produktu \"" << _towary[znajdz_numer(id)]->pobierzNazwa() << "\" zostala zmieniona na: " << _towary[znajdz_numer(id)]->pobierzIlosc() << std::endl;
}

bool Magazyn::sprawdz()const {                                                                            //funkjca sprawdzajaca czy przynajmiej jeden element zostal dodany do wektora klasy magazyn
    if (_towary.size() == 0) {
        std::cout << "Brak elementow w magazynie\nZanim uzyjesz funkcji przyjecie lub odbior dodaj produkt do magazynu funkcja \"dodaj towar\"\n ";
        return true;
    } else return false;
}

bool Magazyn::sprawdz(const int &id)const {
    int znalezione_id;
    for (int i = 0; i < _towary.size(); ++i) {
        if(id == _towary[i]->pobierzID()) {
            znalezione_id=i;
            std::cout << "Wybrales towar \"" << _towary[znalezione_id]->pobierzNazwa() << "\" o ID: " << id<< std::endl;
            return false;
        }
    }
    std::cout<<"Podales ID ktorego nie ma w magazynie\n";
    return true;
}

bool Magazyn::sprawdz( int &id, float &ilosc)const {//funkcja sprawdzajaca czy wybranego przez uzytkownika towaru jest wystarczajaca ilosc by mozna by³o od niej odj¹æ liczbe podana przez uzytkownika

    if(ilosc <= _towary[znajdz_numer(id)]->pobierzIlosc()&& ilosc >= 0)
        return false;
    if (ilosc<0) {
        std::cout << "Nie mozesz odjac ujemnej liczby\n";
        return true;
    }
    else
    {
        std::cout << "Nie ma wystarczajaco sztuk w magazynie.\nAktualna ilosc produktu\"" << _towary[znajdz_numer(id)]->pobierzNazwa() << "\" wynosi: " << _towary[znajdz_numer(id)]->pobierzIlosc() << std::endl;
        return true;
    }
}

int Magazyn::znajdz_numer(int &id) const {
    int znalezione_id;
    for (int i = 0; i < _towary.size(); ++i)
    {
        if(id == _towary[i]->pobierzID())
            znalezione_id = i;
    }
    return znalezione_id;
}

Produkt* Magazyn::pobierzProdukt(int &id) {
    return _towary[znajdz_numer(id)];

}
/*void Magazyn::przyjmij(Paleciak p,int numer)
{
    int znalezione_id;
    for (int i = 0; i < p.pobierzWektor().size(); ++i) {
        if(numer == p.pobierzWektor()[i]->pobierzID())
            znalezione_id = i;
    }

    _towary.push_back(p.pobierzWektor()[znalezione_id]);
}*/