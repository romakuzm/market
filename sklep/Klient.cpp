#include "Klient.h"
#include "Koszyk.h"

#include <algorithm>
#include <string>

void Klient::dodajDoKoszyka() {
    int id;
    bool poprawneId = false;

    do {
        std::cout << "Podaj ID produktu do dodania do koszyka: ";
        std::cin >> id;

        if (std::cin.fail()) {
            std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            poprawneId = true;
        }
    } while (!poprawneId);

    auto it = std::find_if(produkty->begin(), produkty->end(), [id](const Produkt& produkt) {
        return produkt.getId() == id;
        });

    if (it != produkty->end()) {
        koszyk->dodajProdukt(*it);
        std::cout << "Dodano produkt o ID: " << id << " do koszyka." << std::endl;
    }
    else {
        std::cout << "Nie znaleziono produktu o ID: " << id << std::endl;
    }
}

void Klient::usunZKoszyka() {
    int id;
    bool poprawneId = false;

    do {
        std::cout << "Podaj ID produktu do usuniecia z koszyka: ";
        std::cin >> id;

        if (std::cin.fail()) {
            std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            poprawneId = true;
        }
    } while (!poprawneId);

    if (koszyk->usunProdukt(id)) {
        std::cout << "Usunieto produkt o ID: " << id << " z koszyka." << std::endl;
    }
    else {
        std::cout << "Nie znaleziono produktu o ID: " << id << " w koszyku." << std::endl;
    }
}

void Klient::zlozZamowienie(Pracownik& pracownik) {
    if (koszyk->pusty()) {
        std::cout << "Koszyk jest pusty. Nie mozna zlozyc zamowienia." << std::endl;
        return;
    }

    koszyk->pokazKoszyk();

    wybierzMetodePlatnosci();

    pracownik.usunProdukt(*koszyk);

    koszyk->wyczyscKoszyk();

    std::cout << "Zamowienie zostalo zlozone i przekazane do realizacji." << std::endl;
}


void Klient::znajdzProduktPoNazwie() {
        std::string nazwaProduktu;
        std::cout << "Podaj nazwe produktu: ";
        std::cin.ignore();
        std::getline(std::cin, nazwaProduktu);

        std::vector<Produkt> znalezioneProdukty;

        for (const Produkt& produkt : *(produkty)) {
            std::string nazwa = produkt.getNazwa();
            std::transform(nazwa.begin(), nazwa.end(), nazwa.begin(), ::tolower); 
            std::transform(nazwaProduktu.begin(), nazwaProduktu.end(), nazwaProduktu.begin(), ::tolower); 
            
            if (nazwa.find(nazwaProduktu) != std::string::npos) {
                znalezioneProdukty.push_back(produkt);
            }
        }

        if (znalezioneProdukty.empty()) {
            std::cout << "Nie znaleziono produktu o podanej nazwie." << std::endl;
        }
        else {
            std::cout << "Znalezione produkty o nazwie zawierajacej '" << nazwaProduktu << "':" << std::endl;
            for (const Produkt& produkt : znalezioneProdukty) {
                std::cout << "ID: " << produkt.getId() << std::endl;
                std::cout << "Firma: " << produkt.getFirma() << std::endl;
                std::cout << "Model: " << produkt.getModel() << std::endl;
                std::cout << "Cena: $" << produkt.getCena() << std::endl;
                std::cout << "Ilosc: " << produkt.getIlosc() << std::endl;
                std::cout << "Rodzaj: " << produkt.getRodzaj() << std::endl;
                std::cout << "-----------------------------" << std::endl;
            }
        }
    }

void Klient::wybierzMetodePlatnosci() {
    int wybor;

    while (true) {
        std::cout << "Wybierz metode platnosci:" << std::endl;
        std::cout << "1. Karta debetowa" << std::endl;
        std::cout << "2. BLIK" << std::endl;
        std::cout << "Wybor: ";
        std::cin >> wybor;

        if (std::cin.fail()) {
            std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            if (wybor == 1) {
                std::string numerKarty;
                std::string dataWaznosci;
                std::string CVV;

                std::cout << "Podaj numer karty: ";
                std::cin.ignore();
                std::getline(std::cin, numerKarty);

                std::cout << "Podaj date waznosci karty: ";
                std::getline(std::cin, dataWaznosci);

                std::cout << "Podaj kod ochronny: ";
                std::getline(std::cin, CVV);

                std::cout << "Platnosc karta debetowa zostala wykonana." << std::endl;
                break;
            }
            else if (wybor == 2) {
                std::string kodBlik;

                std::cout << "Podaj kod BLIK: ";
                std::cin.ignore();
                std::getline(std::cin, kodBlik);

                std::cout << "Platnosc BLIK zostala wykonana." << std::endl;
                break; 
            }
            else {
                std::cout << "Niepoprawny wybor metody platnosci." << std::endl;
            }
        }
    }
}
void Klient::kontakt() {
    std::cout << "Czesto zadawane pytania:" << std::endl;
    std::cout << "1. Jak moge zlozyc zamowienie?" << std::endl;
    std::cout << "2. Jak sprawdzic status mojego zamowienia?" << std::endl;
    std::cout << "3. Czy akceptujecie zwroty?" << std::endl;
    std::cout << "4. Jak moge sprawdzic dostepnosc danego produktu?" << std::endl;
}

