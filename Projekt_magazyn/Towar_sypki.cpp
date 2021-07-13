//
// Created by £ukasz on 25.02.2021.
//

#include "Towar_sypki.h"
void Towar_sypki::dodaj( float &n)
{
    _waga_kg +=n;
    _waga_calego_towaru +=n;
}
void Towar_sypki::odejmij( float &n)
{
    _waga_kg -=n;
    _waga_calego_towaru -=n;
}

/*Towar_sypki& Towar_sypki::operator+=(const float n) {                             //operator zwiekszania wartosci zmiennej prywatnej _ilosc o n czyli przekazana liczbe
    _waga_kg +=n;
    return *this;
}
Towar_sypki& Towar_sypki::operator-=(const float n) {                             //operator zmniejszaniawartosci zmiennej prywatnej _ilosc o n czyli przekazana liczbe
    _waga_kg -= n;
    return *this;

}*/
