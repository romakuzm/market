#pragma once
#include "Produkt.h"
#include "Pracownik.h"

#include <vector>

class Sklep {
private:
    std::string nazwa;
    std::vector<Produkt> produkty;
    std::vector<Pracownik> pracownicy;
public:
    Sklep(const std::string& nazwa) : nazwa(nazwa) {}

    void generowaniePrzebiegu();

    void wczytajDaneZExcela(const std::string& nazwaPliku);

    void wyswietlAsortyment() const;
   
    bool czyWczytanoDanePoprawnie() const {
        return !produkty.empty();
    }

    std::vector<Produkt>* getProdukty() {
        return &produkty;
    }
    };