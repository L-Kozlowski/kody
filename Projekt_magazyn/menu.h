//
// Created by £ukasz on 25.02.2021.
//

#ifndef PROJEKT_MAGAZYN_MENU_H
#define PROJEKT_MAGAZYN_MENU_H
#include "Lista_magazynow.h"
#include "funkcje_pomocnicze.h"
#include "obsluga_funkcji_menu.h"
#include <iostream>
using namespace std;

void menu_magazyn(Lista_magazynow &listaMagazynow, Paleciak &paleciak);
void menu_paleciak(Lista_magazynow &listaMagazynow, Paleciak &paleciak);
void menu_wyswietlanie(Lista_magazynow &listaMagazynow, const Paleciak& paleciak);
int menu() {
    int wybor;
    Lista_magazynow lista_stworzonych_magazynow;
    lista_stworzonych_magazynow.rozszerza();
    Paleciak paleciak;

    do {
        cout << "\n---====== MENU =====---\n"                                                // Menu
                "1: Magazyn\n"                                    // dodaje towaru do magazynu
                "2: Paleciak\n"                // dodanie okreœlonej ilosci wybranego towaru
                "3: Wyswietlanie\n"                  // usuniecie okreœlonej ilosci wybranego towaru
                "0: Wylaczenie programu\n"                                                  // zakoñczenie dziaalania
                "-----------------------\n"

                "Wybierz akcje: " << endl;
        wybor = pobierzInt();

        switch (wybor) {                       // Wybor odpowiedniej funkcji
            case 0:
                cout<<"Wylaczenie programu";
                return 0;
            case 1:
                menu_magazyn(lista_stworzonych_magazynow,paleciak);
                break;
            case 2:
                menu_paleciak(lista_stworzonych_magazynow,paleciak);
                break;
            case 3:
                menu_wyswietlanie(lista_stworzonych_magazynow,paleciak);
                break;
            default:
                cout << "Niepoprawny wybor" << endl;
        }
    } while (true);
}
void menu_magazyn(Lista_magazynow &listaMagazynow, Paleciak &paleciak)
{
    int wybor;
    do {
        cout << "\n  ---====== MENU =====---\n"
                "\n---====== MAGAZYN =====---\n"
                "1: Dodaj towar do wybranego magazynu\n"                                    // dodaje towaru do magazynu
                "2: Przyjecie- dodaj ilosc towaru do produktu w magazynie\n"                // dodanie okreœlonej ilosci wybranego towaru
                "3: Odbior - dodaj ilosc towaru do produktu w magazynie\n"                  // usuniecie okreœlonej ilosci wybranego towaru
                "4: Przenies z magazynu na paleciak\n"
                "5: Przenies z paleciaka na magazyn\n"                                                   //
                "6: Stworz nowy magazyn\n"
                "7: Pokaz magazyny\n"
                "0: Powrot do menu glownego\n"
                "-----------------------\n"

                "Wybierz akcje: " << endl;

        wybor = pobierzInt();

        switch (wybor) {                       // Wybor odpowiedniej funkcji
            case 0:
                cout<<"Cofanie";
                return;
            case 1:
                dodawanie_nowego_towaru_do_magazynu(listaMagazynow);
                break;
            case 2:
                zamiana_ilosci_towaru(listaMagazynow,wybor);
                break;
            case 3:
                zamiana_ilosci_towaru(listaMagazynow,wybor);
                break;
            case 4:
                oddaj_z_magazynu_na_paleciak(listaMagazynow,paleciak);
                break;
            case 5:
                oddaj_z_paleciaka_na_magazyn(listaMagazynow,paleciak);
                break;
            case 6:
                listaMagazynow.rozszerza();
                break;
            case 7:
                listaMagazynow.wyswietlanie();
                break;
            default:
                cout << "Niepoprawny wybor" << endl;
        }
    } while (true);
}
void menu_paleciak(Lista_magazynow &listaMagazynow, Paleciak &paleciak)
{
    int wybor;
    do {
        cout << "\n  ---====== MENU =====---\n"
                "\n---====== PALECIAK =====---\n"
                "1: Dodaj na plaeciak\n"                                                    //
                "2: Wyswietl paleciak\n"                                                    //
                "3: Przenies z paleciaka na magazyn\n"                                                   //
                "4: Przenies z magazynu na paleciak\n"                                                    //
                "0: Powrot do menu glownego\n"                                                 // zakoñczenie dziaalania
                "-----------------------\n"

                "Wybierz akcje: " << endl;
        wybor = pobierzInt();

        switch (wybor) {                       // Wybor odpowiedniej funkcji
            case 0:
                cout<<"Cofanie";
                return;
            case 1:
                stworz_obiekt_na_paleciaku(paleciak);
                break;
            case 2:
                paleciak.wyswietl();
                break;
            case 3:
                oddaj_z_paleciaka_na_magazyn(listaMagazynow,paleciak);
                break;
            case 4:
                oddaj_z_magazynu_na_paleciak(listaMagazynow,paleciak);
                break;
            default:
                cout << "Niepoprawny wybor" << endl;
        }
    }while (true);
}
void menu_wyswietlanie(Lista_magazynow &listaMagazynow, const Paleciak &paleciak)
{
    int wybor;
    do {
        cout << "\n  ---====== MENU =====---\n"
                "\n---====== WYSWIETLANIE=====---\n"
                "1: Wyswietl wszystkie magazyny\n"                                                    //
                "2: Wyswietl paleciak\n"                                                    //                 //
                "0: Powrot do menu glownego\n"                                                 // zakoñczenie dziaalania
                "-----------------------\n"

                "Wybierz akcje: " << endl;
        wybor = pobierzInt();
        switch (wybor) {                       // Wybor odpowiedniej funkcji
            case 0:
                cout<<"Cofanie";
                return;
            case 1:
                listaMagazynow.wyswietlanie();
                break;
            case 2:
                paleciak.wyswietl();
                break;
            default:
                cout << "Niepoprawny wybor" << endl;
        }

    }while (true);


    }

#endif //PROJEKT_MAGAZYN_MENU_H