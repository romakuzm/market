#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Pracownik.h"
#include "Produkt.h"

void Pracownik::dodajProdukt() {
    srand(time(nullptr));
    int losowa = rand() % 100;

    if (losowa < 90) {

        int index = rand() % produkty->size();
        int ilosc = 1;
        (*produkty)[index].zwiekszIlosc(ilosc);
        std::cout << "Dodano " << ilosc << " sztuk produktu o ID: " << (*produkty)[index].getId() << std::endl;
    }
    else if (losowa < 10) {

        int id;
        std::string nazwa;
        std::string firma;
        std::string model;
        double cena;
        int ilosc;
        std::string rodzaj;

 
        std::cout << "Dodawanie nowego produktu" << std::endl;
        std::cout << "ID: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Nazwa: ";
        std::getline(std::cin, nazwa);
        std::cout << "Firma: ";
        std::getline(std::cin, firma);
        std::cout << "Model: ";
        std::getline(std::cin, model);
        std::cout << "Cena: ";
        std::cin >> cena;
        std::cout << "Ilosc: ";
        std::cin >> ilosc;
        std::cout << "Rodzaj: ";
        std::cin.ignore();
        std::getline(std::cin, rodzaj);


        Produkt nowyProdukt(id, nazwa, firma, model, ilosc, cena, rodzaj);
        produkty->push_back(nowyProdukt);

        std::cout << "Dodano nowy produkt o ID: " << id << std::endl;
    }
}

void Pracownik::usunProdukt(Koszyk& koszyk) {
    for (const Produkt& produkt : koszyk.getProdukty()) {
        int id = produkt.getId();
        auto it = std::find_if(produkty->begin(), produkty->end(), [id](const Produkt& p) {
            return p.getId() == id;
            });

        if (it != produkty->end()) {
            if (it->getIlosc() > 0) {
                it->zmniejszIlosc(1);
            }
            else {
                std::cout << "Nie można zmniejsszyc ilosci produktu o ID: " << id << " (ilosc wynosi 0)." << std::endl;
            }
        }
        else {
            std::cout << "Nie znaleziono produktu o ID: " << id << std::endl;
        }
    }
}


void Pracownik::usunProdukt() {
    srand(time(nullptr));
    int losowa = rand() % 100;

    if (losowa < 90) {
        int index = rand() % produkty->size();
        int ilosc = 1;

        if ((*produkty)[index].getIlosc() > 0) {
            (*produkty)[index].zmniejszIlosc(ilosc);
            std::cout << "Zmniejszono ilosc produktu o ID: " << (*produkty)[index].getId() << " o 1 sztuke." << std::endl;
        }
        else {
            std::cout << "Nie można zmniejszyc ilosci produktu o ID: " << (*produkty)[index].getId() << " (ilosc wynosi 0)." << std::endl;
        }
    }
    else {
        int id;

        while (true) {
            std::cout << "Podaj ID produktu do usuniecia: ";
            std::cin >> id;

            if (std::cin.fail()) {
                std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else {
                auto it = std::find_if(produkty->begin(), produkty->end(), [id](const Produkt& produkt) {
                    return produkt.getId() == id;
                    });

                if (it != produkty->end()) {
                    produkty->erase(it);
                    std::cout << "Usunieto produkt o ID: " << id << " z asortymentu." << std::endl;
                }
                else {
                    std::cout << "Nie znaleziono produktu o ID: " << id << std::endl;
                }

                break; 
            }
        }
    }
}

void Pracownik::kontakt() {
    std::cout << std::endl;
    std::cout << "Odpowiedzi na pytania : " << std::endl;
    std::cout << "1. Aby zlozyc zamowienie, dodaj produkty do koszyka, a następnie przejdz do procesu zamawiania i wybierz preferowana metode platnosci." << std::endl;
    std::cout << "2. Aby sprawdzic status zamowienia, zaloguj sie na swoje konto, przejdz do historii zamowien i tam znajdziesz informacje o aktualnym stanie zamowienia." << std::endl;
    std::cout << "3. Tak, akceptujemy zwroty. Prosimy o zapoznanie sie z nasza polityka zwrotow na stronie internetowej, gdzie znajdziesz wszystkie niezbedne informacje dotyczace procedury zwrotow." << std::endl;
    std::cout << "4. Aby sprawdzic dostepnosc produktu, mozesz skorzystac z funkcji wyszukiwania na naszej stronie i wybrac interesujacy cie produkt. " << std::endl;
}