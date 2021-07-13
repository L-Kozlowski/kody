//
// Created by £ukasz on 25.02.2021.
//

#ifndef PROJEKT_MAGAZYN_LISTA_MAGAZYNOW_H
#define PROJEKT_MAGAZYN_LISTA_MAGAZYNOW_H
#include <vector>
#include "Magazyn.h"
#include "Paleciak.h"
class Lista_magazynow {

    std::vector<Magazyn> _lista_mag;              // tworzenie wektora

public:
    Lista_magazynow()= default ;
    void rozszerza();

    void dodawanie(int &numer, Produkt* p );
    void wyswietlanie();
    void wyswietlanie(int &numer);


    void przyjecie(int &numer, int &id, float &ilosc){_lista_mag[numer].przyjecie(id,ilosc);};
    void odbior(int &numer, int &id, float &ilosc){_lista_mag[numer].odbior(id,ilosc);};

    bool sprawdzanie(int &numer)const{return _lista_mag[numer].sprawdz();};                    //przeladowanie funkcji sprawdz
    bool sprawdzanie(int &numer,const int &id) const{return _lista_mag[numer].sprawdz(id);};
    bool sprawdzanie(int &numer, int &id, float &ilosc) const{return _lista_mag[numer].sprawdz(id,ilosc);};

    float pobierzIlosc(int &numer,int &id){return _lista_mag[numer].pobierzIlosc(id);}


    void usuwanie(int &numer_magazynu,int &numer_id){_lista_mag[numer_magazynu].usuwanie(numer_id);}

    bool sprawdz(int &numer);

    Produkt* pobierzProdukt(int &numer,int &id){return _lista_mag[numer].pobierzProdukt(id);}
    //void dodawanie(int numer,std::string nazwa,int typ,int numer_id,float ilosc,float waga);
    //int pobierzWielkosc(){return _lista_mag.size();}
    //void przyjmij(int numer_magazynu,Paleciak p, int numer_id){_lista_mag[numer_magazynu].przyjmij(p,numer_id);}
    //std::vector<Produkt*>  pobierzWektor(int numer){return _lista_mag[numer].pobierzWektor2();}
    //int pobierzWielkosc(int numer){return _lista_mag[numer].pobierzWielkosc();}

};


#endif //PROJEKT_MAGAZYN_LISTA_MAGAZYNOW_H
