//
// Created by £ukasz on 25.02.2021.
//

#include "Towar_na_sztuki.h"


void Towar_na_sztuki::dodaj(float &n) {
    //float waga_sztuki = _waga_calego_towaru/_ilosc;
    _ilosc+=n;
    _waga_calego_towaru+=n*_waga_sztuki;
}
void Towar_na_sztuki::odejmij(float &n) {
    //float waga_sztuki = _waga_calego_towaru/_ilosc;
    _ilosc-=n;
    _waga_calego_towaru-=n*_waga_sztuki;
}


/*Towar_na_sztuki& Towar_na_sztuki::operator+=(const int n) {                             //operator zwiekszania wartosci zmiennej prywatnej _ilosc o n czyli przekazana liczbe
    _ilosc +=n;
    return *this;
}
Towar_na_sztuki& Towar_na_sztuki::operator-=(const int n) {                             //operator zmniejszaniawartosci zmiennej prywatnej _ilosc o n czyli przekazana liczbe
    _ilosc -= n;
    return *this;
}*/

/*Towar_na_sztuki* Towar_na_sztuki::podziel(int id,Towar_na_sztuki* t,int nowa_ilosc) {

    t->odejmij(nowa_ilosc);
    Towar_na_sztuki* w;
    w = new Towar_na_sztuki(id,t->pobierzNazwa(),nowa_ilosc);

    return w;
}
void Towar_na_sztuki::scal(Towar_na_sztuki* t,Towar_na_sztuki* t2)
{
    t->dodaj(t2->pobierzIlosc());
}*/
/*std::ostream& operator<<(std::ostream& os, const Towar_na_sztuki& t)          //zaprzyjaznienie znaku << by moc wypisywac wektor
{
    os <<"|\t"<< t._id<<"\t|\t";
    bool sprawdz = true;//fragment kodu odpowiadajacy za skrocenie nazwy przy wypisywaniu gdy jest za d³uga i mogla by przesunac kolumny
    for(int i = 0;i<13; i++) {                                      //petla wypisujaca kolejne litery ze zmniennej nazwa, gdy natrafi na symbol \0 konczy wypisywanie wypisujac do konca petli same spacje
        if (t._nazwa[i] == '\0') {
            sprawdz = false;
        }
        if (sprawdz == true)
            os << t._nazwa[i];
        else
            os << " ";
    }
    if(t._nazwa.length()>14)                                        //gdy nazwa jest za dluga dopisuje na jej koncu kropeczki by zasygnalizowac uzytkownikowi o skroceniu zapisu nazwy produktu
        os<<"..";

    os <<"\t\t|\t" <<t._ilosc<<"\t|"<<std::endl;
    return os;
}*/
