#pragma once
#include <iostream>

class Uzytkownik {
private:
    std::string nazwa;
    std::string login;
    std::string haslo;
    bool zalogowany = false;
public:
    void zaloguj();

    void wyloguj();

    std::string getLogin() {
        return login;
    }
    void setLogin(std::string Login) {
        login = Login;
    }
    std::string getHaslo() {
        return haslo;
    }
    void setHaslo(std::string Haslo) {
        haslo = Haslo;
    }

    bool czyZalogowany() {
        return zalogowany;
    }

    virtual void kontakt() {
        std::cout << "Domyślny kontakt z użytkownikiem." << std::endl;
    }

};