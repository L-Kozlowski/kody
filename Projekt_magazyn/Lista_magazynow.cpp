//
// Created by £ukasz on 25.02.2021.
//

#include "Lista_magazynow.h"
void Lista_magazynow::rozszerza() {                                                               //metoda odpowiedzialna za dodawanie nowego towaru do wekotra klasy magazyn
    _lista_mag.emplace_back();
}

void Lista_magazynow::dodawanie(int &numer, Produkt* p )
{
    _lista_mag[numer].dodaj(p);
}

void Lista_magazynow::wyswietlanie()
{
    std::cout<<"Narzie stworzyles tyle magazynow: "<<_lista_mag.size()<<std::endl;
    for (int i = 0; i < _lista_mag.size(); i++) {
        cout << "\nMagazyn nr: " << i;
        cout << "\n------------------------------------\n";
        _lista_mag[i].wyswietl();
        cout << "\n------------------------------------\n";
    }
}
void Lista_magazynow::wyswietlanie(int &numer)
{
    cout << "\nMagazyn nr: " << numer;
    cout << "\n------------------------------------\n";
    _lista_mag[numer].wyswietl();
    cout << "\n------------------------------------\n";

}
bool Lista_magazynow::sprawdz(int &numer) {
    for (int i = 0; i<_lista_mag.size(); i++) {
        if(i==numer)
            return false;
    }

    return true;
}

/*void Lista_magazynow::dodawanie(int numer,std::string nazwa,int typ,int numer_id,float ilosc,float waga)
{
    _lista_mag[numer].dodaj(nazwa,typ,numer_id,ilosc,waga);
}*/