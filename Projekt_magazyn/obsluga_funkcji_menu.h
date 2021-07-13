#include "Produkt.h"
#include "Towar_sypki.h"
#include "Towar_na_sztuki.h"
#include "Towar_ciekly.h"
static int numer_id{0};
Produkt* tworzenie();
void dodawanie_nowego_towaru_do_magazynu(Lista_magazynow &lista_mag);
void zamiana_ilosci_towaru(Lista_magazynow &lista_mag, int &wybor);
void stworz_obiekt_na_paleciaku(Paleciak &paleciak);
void oddaj_z_paleciaka_na_magazyn(Lista_magazynow &lista_mag,Paleciak &paleciak);
void oddaj_z_magazynu_na_paleciak(Lista_magazynow &lista_mag,Paleciak &paleciak);
Produkt* podziel(Produkt* p, float &ilosc);
void scal(Lista_magazynow &listaMagazynow,Paleciak &paleciak,int &numer,int &id,float &ilosc,int &opcja);

Produkt* tworzenie() {
    Produkt *p;

    string nazwa;
    int typ{0};
    float waga_sztuki_towaru{0};
    float waga_calego_towaru{0};
    float ilosc;
    int decyzja{1};

    cout << "\nPodaj nazwe nowego towaru :";
    nazwa = pobierzString();

    do {
    cout << "\nWybierz jakiego typu jest wprowadzany towar (Wyjscie z funkcji wpisz -1):\n";
    cout << "\n1 - Towar na sztuki";
    cout << "\n2 - Towar sypki";
    cout << "\n3 - Towar ciekly\n";
    cout << "\nPodaj typ towaru:";
    typ = pobierzInt();

    }while (typ !=1 && typ !=2 && typ !=3);

    if(typ == 1) {
        do {
            cout << "\nPodaj ilosc towaru\n";
            ilosc = pobierzFloat();
            if (ilosc < 0)
                cout << "\n Ilosc nie moze byc mniejsza od zera\n";
        } while (ilosc < 0);


        do {
            cout << "\nWybierz sposob wprowadzaenia wagi towaru\n";
            cout << "\n1 - Calkowita waga towaru\n";
            cout << "\n2 - Waga jednej sztuki towaru\n";
            decyzja = pobierzInt();
            if (decyzja != 1 && decyzja != 2)
                cout << "\nPodales zla liczbe. Sprobuj jeszcze raz:\n";
        } while (decyzja != 1 && decyzja != 2);
    }
    if(decyzja ==1)
    {
        cout << "\nPodaj calkowita waga towaru\n";
        waga_calego_towaru = pobierzFloat();
    }
    if(decyzja == 2)
    {
        cout << "\nPodaj waga jednej sztuki towaru\n";
        waga_sztuki_towaru = pobierzFloat();
        waga_calego_towaru = waga_sztuki_towaru * ilosc;
    }
    if(typ!=1)
        ilosc=waga_calego_towaru;


    if(typ == 1)
      p = new Towar_na_sztuki(numer_id,nazwa,waga_calego_towaru/ilosc,ilosc,waga_calego_towaru);
    if(typ== 2)
       p = new Towar_sypki(numer_id,nazwa,waga_calego_towaru);
    if(typ== 3)
       p = new Towar_ciekly(numer_id,nazwa,waga_calego_towaru);
    std::cout << "Dodales produkt \"" << nazwa << "\", ktorego ID wynosi: " << numer_id << std::endl;
    numer_id++;
    return p;
}

void dodawanie_nowego_towaru_do_magazynu(Lista_magazynow &lista_mag)
{
    int numer_magazynu;

    lista_mag.wyswietlanie();
    do {
        cout << "Podaj numer magazynu (Wyjscie z funkcji wpisz -1)";
        numer_magazynu = pobierzInt();
        if(numer_magazynu == -1)
            return;

    }while(lista_mag.sprawdz(numer_magazynu));

    lista_mag.dodawanie(numer_magazynu, tworzenie());
}

void zamiana_ilosci_towaru(Lista_magazynow &lista_mag, int &wybor)
{
    lista_mag.wyswietlanie();
    cout << "Podaj w jakim magazynie chcesz dokonac zmiany";
    int numer;
    numer = pobierzInt();

    if(lista_mag.sprawdzanie(numer)){return;}                                        //sprawdzenie czy w magazynie ejst przynajmniej jeden element dla ktorego mozna wywolac funkcje przyjecie/odbior. Jesli magazyn jest pusty wychodzi z funkcji

    float ilosc;
    int id;

    lista_mag.wyswietlanie(numer);                                                   //wyswietlenie listy magazynu by uzytkownik mogl zdecydowac jaki towar wybrac
    do {
        cout << "Podaj ID towaru ktorego chcesz zmienic ilosc:";
        id = pobierzInt();

    }while (lista_mag.sprawdzanie(numer,id));                                         //wywolanie metody sprawdzajacej czy podane id znjaduje sie w magazynie

    if(wybor == 2)                                                  //wejscie do metody przyjecie lub odbior w zaleznosci od wczesniejszego wyboru uzytkownika
    {
        cout << "Podaj ile towaru chcesz przyjac:";
        ilosc = pobierzFloat();
        lista_mag.przyjecie(numer,id,ilosc);                                      // wywolanie metody przyjecie
    } else
    {
        do {
            cout << "Podaj ile towaru chcesz odebrac:";
            ilosc = pobierzFloat();
        }while (lista_mag.sprawdzanie(numer,id,ilosc));                               //sprawdzenie czy podana przez uzytkownika ilosc nie przekracza zapisanej w klasie towar ilosci dla wybranego produktu
        lista_mag.odbior(numer,id,ilosc);
    }
}

void stworz_obiekt_na_paleciaku(Paleciak &paleciak)                                              // Funkcja w mainie odpowiedzialna za odawanie nowego produktu do klasy magazyn
{
    paleciak.wyswietl();
    paleciak.dodaj_obiekt_na_paleciak(tworzenie());
    paleciak.udzwig();
}

void oddaj_z_paleciaka_na_magazyn(Lista_magazynow &lista_mag,Paleciak &paleciak) {

    float ilosc;
    int id;

    paleciak.wyswietl();
    //wyswietlenie listy magazynu by uzytkownik mogl zdecydowac jaki towar wybrac
    do {
        cout << "Podaj ID towaru ktorego chcesz przeniesc na magazyn (Wyjscie z funkcji wpisz -1):";
        id = pobierzInt();
        if(id == -1)
            return;
    } while (paleciak.sprawdzanie(id));                                         //wywolanie metody sprawdzajacej czy podane id znjaduje sie w magazynie

    lista_mag.wyswietlanie();
    int numer;
    do {
        cout << "Podaj w jakim magazynie chcesz dokonac zmiany (Wyjscie z funkcji wpisz -1):";
        numer = pobierzInt();
        if(numer == -1)
            return;
    }while (lista_mag.sprawdz(numer));


    paleciak.wyswietl();//sprawdzenie czy w magazynie ejst przynajmniej jeden element dla ktorego mozna wywolac funkcje przyjecie/odbior. Jesli magazyn jest pusty wychodzi z funkcji

    do {
        cout << "\nPodaj ilosc towaru\n";
        ilosc = pobierzFloat();
        if (paleciak.sprawdzanie(id,ilosc))
            cout << "\n Ilosc nie moze byc mniejsza od zera\n";
    } while (paleciak.sprawdzanie(id,ilosc));

    float ilosc_w_produkcie = paleciak.pobierzIlosc(id);
    Produkt *z;
    if(lista_mag.sprawdzanie(id) && ilosc != ilosc_w_produkcie) {
        z = podziel(paleciak.pobierzProdukt(id), ilosc);
        lista_mag.dodawanie(numer,z);
    }
    else if(!(lista_mag.sprawdzanie(id)) && ilosc == ilosc_w_produkcie)
    {
        int opcja = 2;
        scal(lista_mag,paleciak,numer,id,ilosc,opcja);
        //lista_mag.usuwanie(numer,id);
    }
    else if(lista_mag.sprawdzanie(id) && ilosc == ilosc_w_produkcie)
    {
        z = paleciak.pobierzProdukt(id);
        lista_mag.dodawanie(numer,z);
        paleciak.usuwanie(id);
    }
    else{
        paleciak.odejmij_ilosc(id,ilosc);
        lista_mag.przyjecie(numer,id,ilosc);
    }

    z = nullptr;
    delete (z);
}

void oddaj_z_magazynu_na_paleciak(Lista_magazynow &lista_mag,Paleciak &paleciak)
{
    float ilosc;
    int id;

    lista_mag.wyswietlanie();
    int numer;
    do {
        cout << "Podaj w jakim magazynie chcesz dokonac zmiany (Wyjscie z funkcji wpisz -1):";
        numer = pobierzInt();
        if(numer == -1)
            return;
    }while (lista_mag.sprawdz(numer));

    lista_mag.wyswietlanie(numer);            //wyswietlenie listy magazynu by uzytkownik mogl zdecydowac jaki towar wybrac
    do {
        cout << "Podaj ID towaru ktorego chcesz przeniesc na paleciaka (Wyjscie z funkcji wpisz -1):";
        id = pobierzInt();
        if(id == -1)
            return;

    } while (lista_mag.sprawdzanie(numer,id));                                         //wywolanie metody sprawdzajacej czy podane id znjaduje sie w magazynie

    //sprawdzenie czy w magazynie ejst przynajmniej jeden element dla ktorego mozna wywolac funkcje przyjecie/odbior. Jesli magazyn jest pusty wychodzi z funkcji
    lista_mag.wyswietlanie(numer);
    // int typ = paleciak.pobierzTyp(id);

    do {
        cout << "\nPodaj ilosc towaru\n";
        ilosc = pobierzFloat();
        if (lista_mag.sprawdzanie(numer,id,ilosc))
            cout << "\n Ilosc nie moze byc mniejsza od zera\n";
    } while (lista_mag.sprawdzanie(numer,id,ilosc));

    float ilosc_w_produkcie = lista_mag.pobierzIlosc(numer,id);
    Produkt *z;
    if(paleciak.sprawdzanie(id) && ilosc != ilosc_w_produkcie) {
        z = podziel(lista_mag.pobierzProdukt(numer, id), ilosc);
        paleciak.dodaj_obiekt_na_paleciak(z);
    }
    else if(!(paleciak.sprawdzanie(id)) && ilosc == ilosc_w_produkcie)
    {
        int opcja = 1;
        scal(lista_mag,paleciak,numer,id,ilosc,opcja);
        //lista_mag.usuwanie(numer,id);
    }
    else if(paleciak.sprawdzanie(id) && ilosc == ilosc_w_produkcie)
    {
        z = lista_mag.pobierzProdukt(numer,id);
        paleciak.dodaj_obiekt_na_paleciak(z);
        lista_mag.usuwanie(numer,id);
    }
    else{
        lista_mag.odbior(numer,id,ilosc);
        paleciak.dodaj_ilosc(id,ilosc);
    }

    z = nullptr;
    delete (z);
}

Produkt* podziel(Produkt* p,float &ilosc)
{
    Produkt *k;
    k = nullptr;

    int typ = p->pobierzTyp();
    if(typ == 1)
        k = new Towar_na_sztuki(p->pobierzID(),p->pobierzNazwa(),p->pobierzWageCalkowita()/p->pobierzIlosc());
    if(typ== 2)
        k = new Towar_sypki(p->pobierzID(),p->pobierzNazwa());
    if(typ== 3)
        k = new Towar_ciekly(p->pobierzID(),p->pobierzNazwa());

    p->odejmij(ilosc);
    k->dodaj(ilosc);

    return k;
}

void scal(Lista_magazynow &listaMagazynow,Paleciak &paleciak,int &numer,int &id,float &ilosc,int &opcja)
{
    if(opcja == 1)
    {
        listaMagazynow.odbior(numer,id,ilosc);
        listaMagazynow.usuwanie(numer,id);
        paleciak.dodaj_ilosc(id,ilosc);
    }
    if(opcja == 2)
    {
        paleciak.usuwanie(id);
        listaMagazynow.przyjecie(numer,id,ilosc);
    }
}