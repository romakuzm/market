#pragma once
#include "Uzytkownik.h"

void Uzytkownik::zaloguj() {
    if (zalogowany) {
        std::cout << "Uzytkownik jest juz zalogowany." << std::endl;
        return;
    }
    std::string wprowadzonyLogin;
    std::string wprowadzoneHaslo;

  
    std::cout << "Podaj login: ";
    std::cin >> wprowadzonyLogin;

    std::cout << "Podaj haslo: ";
    std::cin >> wprowadzoneHaslo;

    if (wprowadzonyLogin == login && wprowadzoneHaslo == haslo) {
        zalogowany = true;
        std::cout << "Zalogowano." << std::endl;
    }
    else {
        zalogowany = false;
        std::cout << "Niepoprawny login lub haslo." << std::endl;
    }
}

void Uzytkownik::wyloguj() {
    zalogowany = false;
    std::cout << "Zostales wylogowany. Powodzenia!" << std::endl;
}
