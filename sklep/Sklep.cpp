#include "Sklep.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "Sklep.h"
#include "Klient.h"
#include "Pracownik.h"


void Sklep::generowaniePrzebiegu() {
    bool zalogowany = false;
    std::vector<Produkt>* produktySklepu = getProdukty();
    Klient klient(produktySklepu);
    Pracownik pracownik(produktySklepu);

    std::cout << "Logowanie" << std::endl;
    std::cout << "Wybierz tryb logowania:\n";
    std::cout << "1. Klient\n";
    std::cout << "2. Pracownik\n";
    std::cout << "Wybor: ";

    int trybLogowania;
    std::cin >> trybLogowania;
    std::string login, haslo;

    switch (trybLogowania) {
    case 1:
        while (!zalogowany) {
            std::cout << "Podaj login: ";
            std::cin >> login;
            std::cout << "Podaj haslo: ";
            std::cin >> haslo;

            klient.setLogin(login);
            klient.setHaslo(haslo);
            klient.zaloguj();
            zalogowany = klient.czyZalogowany();

            if (zalogowany) {
                bool kontynuuj = true;

                while (kontynuuj) {
                    std::cout << std::endl;
                    std::cout << "Tryb klienta" << std::endl;
                    std::cout << "1. Dodaj produkt do koszyka" << std::endl;
                    std::cout << "2. Usun produkt z koszyka" << std::endl;
                    std::cout << "3. Wyszukaj produkt wedlug nazwy" << std::endl;
                    std::cout << "4. Wyswietl koszyk" << std::endl;
                    std::cout << "5. Oblicz wartosc koszyka" << std::endl;
                    std::cout << "6. Zloz zamowienie" << std::endl;
                    std::cout << "7. Skontaktuj sie z pracownikiem" << std::endl;
                    std::cout << "8. Przelacz na tryb pracownika" << std::endl;
                    std::cout << "9. Wyloguj" << std::endl;
                    std::cout << "Wybierz opcje: ";
                    int wybor;
                    std::cin >> wybor;
                    if (std::cin.fail()) {
                        std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }

                    switch (wybor) {
                    case 1:
                        system("cls");
                        klient.dodajDoKoszyka();
                        break;
                    case 2:
                        system("cls");
                        klient.usunZKoszyka();
                        break;
                    case 3:
                        system("cls");
                        klient.znajdzProduktPoNazwie();
                        break;
                    case 4:
                        system("cls");
                        klient.wyswietlKoszyk();
                        break;
                    case 5:
                        system("cls");
                        klient.obliczWartoscKoszyka();
                        break;
                    case 6:
                        system("cls");
                        klient.zlozZamowienie(pracownik);
                        break;
                    case 7:
                        system("cls");
                        klient.kontakt();
                        pracownik.kontakt();
                        break;
                    case 8:
                        kontynuuj = false;
                        break;
                    case 9:
                        system("cls");
                        klient.wyloguj();
                        kontynuuj = false;
                        break;
                    default:
                        std::cout << "Niepoprawny wybor. Sprobuj ponownie." << std::endl;
                        break;
                    }
                }
            }
            else {
                std::cout << "Bledny login lub haslo. Sprobuj ponownie." << std::endl;
            }
        }
        break;
    case 2:
        while (!zalogowany) {
            std::string login, haslo;
            std::cout << "Podaj login: ";
            std::cin >> login;
            std::cout << "Podaj haslo: ";
            std::cin >> haslo;

            pracownik.setLogin(login);
            pracownik.setHaslo(haslo);
            pracownik.zaloguj();
            zalogowany = pracownik.czyZalogowany();

            if (zalogowany) {
                bool kontynuuj = true;

                while (kontynuuj) {
                    std::cout << std::endl;
                    std::cout << "Tryb pracownika" << std::endl;
                    std::cout << "1. Dodaj nowy produkt" << std::endl;
                    std::cout << "2. Usun produkt" << std::endl;
                    std::cout << "3. Sprawdz pensje" << std::endl;
                    std::cout << "4. Przelacz na tryb klienta" << std::endl;
                    std::cout << "5. Wyloguj" << std::endl;
                    std::cout << "Wybierz opcje: ";
                    int wybor;
                    std::cin >> wybor;
                    if (std::cin.fail()) {
                        std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }

                    switch (wybor) {
                    case 1:
                        system("cls");
                        pracownik.dodajProdukt();
                        break;
                    case 2: {
                        system("cls");
                        pracownik.usunProdukt();
                        break;
                        }
                    case 3:
                        system("cls");
                        pracownik.setPensja(1000);
                        std::cout << "Twoja pensja wynosi " << pracownik.getPensja() << std::endl;
                        break;
                    case 4:
                        kontynuuj = false;
                        break;
                    case 5:
                        system("cls");
                        pracownik.wyloguj();
                        kontynuuj = false;
                        break;
                    default:
                        std::cout << "Niepoprawny wybor. Sprobuj ponownie." << std::endl;
                        break;
                    }
                }
            }
            else {
                std::cout << "Bledny login lub haslo. Sprobuj ponownie." << std::endl;
            }
        }
        break;
    default:
        std::cout << "Niepoprawny tryb logowania." << std::endl;
        break;
    }
}



void Sklep::wczytajDaneZExcela(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik) {
        std::cout << "Blad: Nie mozna otworzyc pliku " << nazwaPliku << std::endl;
        return;
    }

    std::string linia;

    try {
        while (std::getline(plik, linia)) {
            if (linia.empty()) {
                break;
            }

            std::stringstream ss(linia);
            std::string pole;

            std::getline(ss, pole, ';');
            int produkt_id = std::stoi(pole);

            std::getline(ss, pole, ';');
            std::string produkt_nazwa = pole;

            std::getline(ss, pole, ';');
            std::string produkt_firma = pole;

            std::getline(ss, pole, ';');
            std::string produkt_model = pole;

            std::getline(ss, pole, ';');
            double produkt_cena = std::stod(pole);

            std::getline(ss, pole, ';');
            int produkt_ilosc = std::stoi(pole);

            std::getline(ss, pole, ';');
            std::string produkt_rodzaj = pole;

            Produkt nowyProdukt(produkt_id, produkt_nazwa, produkt_firma, produkt_model, produkt_ilosc, produkt_cena, produkt_rodzaj);

            produkty.push_back(nowyProdukt);
        }
    }
    catch (const std::exception& e) {
        std::cout << "Blad: Wystapil wyjatek podczas przetwarzania danych: " << e.what() << std::endl;
    }

    plik.close();
    std::cout << "Dane zostaly wczytane poprawnie" << std::endl;
}




void Sklep::wyswietlAsortyment() const {
    std::cout << "Asortyment sklepu " << nazwa << ":" << std::endl;
    for (const Produkt& produkt : produkty) {
        std::cout << "ID: " << produkt.getId() << std::endl;
        std::cout << "Nazwa: " << produkt.getNazwa() << std::endl;
        std::cout << "Firma: " << produkt.getFirma() << std::endl;
        std::cout << "Model: " << produkt.getModel() << std::endl;
        std::cout << "Cena: $" << produkt.getCena() << std::endl;
        std::cout << "Ilosc: " << produkt.getIlosc() << std::endl;
        std::cout << "Rodzaj: " << produkt.getRodzaj() << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}