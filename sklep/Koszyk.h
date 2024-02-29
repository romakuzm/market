#pragma once
#include <vector>
#include "Produkt.h"

class Koszyk {
private:
    std::vector<Produkt> produkty;
public:
    void dodajProdukt(const Produkt& produkt);
    bool usunProdukt(int id);
    void pokazKoszyk();
    void obliczWartosc();
    bool pusty() const;
    void wyczyscKoszyk();
    const std::vector<Produkt>& getProdukty() const;
};