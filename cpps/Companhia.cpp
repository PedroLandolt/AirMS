//
// Created by pland on 05/01/2023.
//

#include "Companhia.h"

Companhia::Companhia(string codigo, string nome, string sigla, string pais) {
    this->codigo = codigo;
    this->nome = nome;
    this->sigla = sigla;
    this->pais = pais;
}

string Companhia::getCodigo() const {
    return codigo;
}

string Companhia::getNome() const {
    return nome;
}

string Companhia::getSigla() const {
    return sigla;
}

string Companhia::getPais() const {
    return pais;
}

bool Companhia::operator<(const Companhia &cph) const {
    return codigo < cph.codigo;
}
