#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Klient.h"
#include "Sklep.h"





int main()


{
    Sklep sklep("Sklepik");
    int wybor;
    bool koniec = false;
    bool daneWczytane = false;

    std::cout << "Witaj w sklepie internetowym Sklepik!" << std::endl;

    while (!koniec)
    {
        std::cout << "\n\nWybierz jedna z opcji:\n";
        std::cout << "1. Wczytaj dane z pliku CSV\n";
        std::cout << "2. Wyswietl asortyment sklepu\n";
        std::cout << "3. Generuj przebieg\n";
        std::cout << "4. Zakoncz\n";
        std::cout << "Wybor: ";

        std::cin >> wybor;
        if (std::cin.fail()) {
            std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (wybor) {
        case 1: {
            std::string nazwaPliku;
            bool poprawnaNazwaPliku = false;

            while (!poprawnaNazwaPliku) {
                std::cout << "Podaj nazwe pliku CSV: ";
                std::cin >> nazwaPliku;

                sklep.wczytajDaneZExcela(nazwaPliku);
                daneWczytane = true;

                if (sklep.czyWczytanoDanePoprawnie()) {
                    poprawnaNazwaPliku = true;
                }
                else {
                    std::cout << "Podano niepoprawna nazwe pliku. Sprobuj ponownie." << std::endl;
                }
            }
            break;
        }
        case 2:
            system("cls");
            if (!daneWczytane) {
                std::cout << "Najpierw wczytaj dane z pliku CSV.\n";
            }
            else {
                sklep.wyswietlAsortyment();
            }
            break;
        case 3:
            system("cls");
            if (!daneWczytane) {
                std::cout << "Najpierw wczytaj dane z pliku CSV.\n";
            }
            else {
                sklep.generowaniePrzebiegu();
            }
            break;
        case 4:
            koniec = true;
            break;
        default:
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
            break;
        }
    }
    return 0;
}
