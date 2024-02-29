#include "Koszyk.h"

void Koszyk::dodajProdukt(const Produkt& produkt) {
    produkty.push_back(produkt);
}
bool Koszyk::usunProdukt(int id) {
    auto it = std::find_if(produkty.begin(), produkty.end(), [id](const Produkt& produkt) {
        return produkt.getId() == id;
        });

    if (it != produkty.end()) {
        produkty.erase(it);
        return true;
    }

    return false;
}

const std::vector<Produkt>& Koszyk::getProdukty() const {
    return produkty;
}

void Koszyk::wyczyscKoszyk() {
    produkty.clear();
}

void Koszyk::pokazKoszyk() {
        std::cout << "Zawartosc koszyka:" << std::endl;
        for (const Produkt& produkt : produkty) {
            std::cout << "ID: " << produkt.getId() << ", Nazwa: " << produkt.getNazwa() << ", Cena: " << produkt.getCena() << std::endl;
        }
}

void Koszyk::obliczWartosc() {
    float suma = 0.0;
    for (const Produkt& produkt : produkty) {
        suma += produkt.getCena();
    }
    std::cout << "Wartosc koszyka: " << suma << std::endl;
}

bool Koszyk::pusty() const {
    return produkty.empty();
}