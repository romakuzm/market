#pragma once
#include "Uzytkownik.h"
#include "Produkt.h"
#include "Koszyk.h"
#include <vector>

class Pracownik : public Uzytkownik{
private:
    std::vector<Produkt>* produkty;
    float pensja = 0;
public:
    Pracownik(std::vector<Produkt>* produktySklepu)
        : produkty(produktySklepu) {
    }

    void dodajProdukt();

    void usunProdukt(Koszyk& koszyk);
 
    void usunProdukt();

    void setPensja(float Pensja) {
        pensja = Pensja;;
    }
    float getPensja() {
        return pensja;
    }

    void kontakt() override;
};