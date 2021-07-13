//
// Created by £ukasz on 25.02.2021.
//

#include "Towar_ciekly.h"

void Towar_ciekly::dodaj( float &n)
{
    _waga_l += n;
    _waga_calego_towaru += n;
}
void Towar_ciekly::odejmij( float &n)
{
    _waga_l -= n;
    _waga_calego_towaru -= n;
}


/*Towar_ciekly& Towar_ciekly::operator+=(const float n) {                             //operator zwiekszania wartosci zmiennej prywatnej _ilosc o n czyli przekazana liczbe
    _waga_l +=n;
    return *this;
}
Towar_ciekly& Towar_ciekly::operator-=(const float n) {                             //operator zmniejszaniawartosci zmiennej prywatnej _ilosc o n czyli przekazana liczbe
    _waga_l -= n;
    return *this;
}*/
