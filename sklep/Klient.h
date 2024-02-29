#pragma once
#include <iostream>
#include <vector>
#include "Pracownik.h"
#include "Uzytkownik.h"
#include "Produkt.h"

class Koszyk; 

class Klient : public Uzytkownik{
private:
	std::string numTelefonu;
	std::string adres;
	Koszyk* koszyk;
	std::vector<Produkt>* produkty;
public:
	Klient(std::vector<Produkt>* produktySklepu)
		: produkty(produktySklepu) {
		koszyk = new Koszyk();
	}
	~Klient() {
		delete koszyk;
	}
	void dodajDoKoszyka();
	void usunZKoszyka();
	void zlozZamowienie(Pracownik& pracownik);
	void znajdzProduktPoNazwie();
	void wybierzMetodePlatnosci();
	void kontakt() override;
	void obliczWartoscKoszyka() {
		koszyk->obliczWartosc();
	}
	void wyswietlKoszyk() {
		if (koszyk->pusty()) {
			std::cout << "Koszyk jest pusty." << std::endl;
		}
		else {
			koszyk->pokazKoszyk();
		}
	}
};