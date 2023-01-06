//
// Created by pland on 05/01/2023.
//

#include "Aeroporto.h"

Aeroporto::Aeroporto(string codigo, string nome, string cidade, string pais, double latitude, double longitude) {
    this->codigo = codigo;
    this->nome = nome;
    this->cidade = cidade;
    this->pais = pais;
    this->latitude = latitude;
    this->longitude = longitude;
}

string Aeroporto::getCodigo() const {
    return codigo;
}

string Aeroporto::getNome() const {
    return nome;
}

string Aeroporto::getCidade() const {
    return cidade;
}

string Aeroporto::getPais() const {
    return pais;
}

double Aeroporto::getLatitude() const {
    return latitude;
}

double Aeroporto::getLongitude() const {
    return longitude;
}

Aeroporto::Aeroporto() {

}
