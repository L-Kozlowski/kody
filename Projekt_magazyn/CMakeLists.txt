cmake_minimum_required(VERSION 3.17)
project(Projekt_magazyn)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt_magazyn main.cpp menu.h funkcje_pomocnicze.h Produkt.h Towar_na_sztuki.cpp Towar_na_sztuki.h Towar_ciekly.cpp Towar_ciekly.h Towar_sypki.cpp Towar_sypki.h Lista_magazynow.cpp Lista_magazynow.h Magazyn.cpp Magazyn.h Paleciak.cpp Paleciak.h obsluga_funkcji_menu.h)