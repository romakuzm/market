#pragma once
#include <iostream>
#include <string>

class Produkt {
private:
    int id;
    std::string nazwa;
    std::string firma;
    std::string model;
    int ilosc;
    double cena;
    std::string rodzaj;
public:
    Produkt(int produkt_id, std::string produkt_nazwa, std::string produkt_firma, std::string produkt_model, int produkt_ilosc, double produkt_cena, std::string produkt_rodzaj) : id(produkt_id), nazwa(produkt_nazwa), firma(produkt_firma), model(produkt_model),
        ilosc(produkt_ilosc), cena(produkt_cena), rodzaj(produkt_rodzaj) {}
     
    void zwiekszIlosc(int ilosc) {
        this->ilosc += ilosc;
    }

    void zmniejszIlosc(int ilosc) {
        if (this->ilosc >= ilosc) {
            this->ilosc -= ilosc;
        }
        else {
            this->ilosc = 0;
        }
    }

    int getId() const{
        return id;
    }
    std::string getNazwa() const{
        return nazwa;
    }
    std::string getFirma() const{
        return firma;
    }
    std::string getModel() const{
        return model;
    }
    std::string getRodzaj() const{
        return rodzaj;
    }
    int getIlosc() const{
        return ilosc;
    }
    double getCena() const{
        return cena;
    }
    void setId(int ID) {
        id = ID;
    }
    void setNazwa(const std::string& Nazwa) {
        nazwa = Nazwa;
    }
    void setFirma(const std::string& Firma) {
        firma = Firma;
    }
    void setModel(const std::string& Model) {
        model = Model;
    }
    void setIlosc(int Ilosc) {
        ilosc = Ilosc;
    }
    void setCena(float Cena) {
        cena = Cena;
    }
    void setRodzaj(const std::string& Rodzaj) {
        rodzaj = Rodzaj;
    }
};