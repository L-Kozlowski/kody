//
// Created by £ukasz on 25.02.2021.
//

#ifndef PROJEKT_MAGAZYN_FUNKCJE_POMOCNICZE_H
#define PROJEKT_MAGAZYN_FUNKCJE_POMOCNICZE_H

#include <iostream>
#include <string>
using namespace std;

float pobierzFloat()                                                  // funkcja pobieraj¹ca od uzytkownika wartosc float// i sprawdzajaca czy uzytkownik przez przypadek nie podal liter
{
    float linia;

        while( !( cin >> linia ) )
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Nie podales liczby typu calkowitego\nSprobuj jeszcze raz: ";
        }
        cin.ignore(1000,'\n');

    return linia;
}

string pobierzString()                                              // funkcja pobieraj¹ca od uzytkownika stringa
{
    string linia;
    getline(cin, linia);
    return linia;
}

int pobierzInt()                                                  // funkcja pobieraj¹ca od uzytkownika wartosc float// i sprawdzajaca czy uzytkownik przez przypadek nie podal liter
{
    int linia;

    while( !( cin >> linia ) )
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Nie podales liczby typu calkowitego\nSprobuj jeszcze raz: ";
    }
    cin.ignore(1000,'\n');

    return linia;
}

#endif //PROJEKT_MAGAZYN_FUNKCJE_POMOCNICZE_H
