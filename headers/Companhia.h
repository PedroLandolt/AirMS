//
// Created by pland on 05/01/2023.
//

#ifndef AIRLINE_H
#define AIRLINE_H

#include <bits/stdc++.h>

using namespace std;

class Companhia {

    string codigo;
    string nome;
    string sigla;
    string pais;

public:

    Companhia(string codigo, string nome, string sigla, string pais);

    string getCodigo() const;
    string getNome() const;
    string getSigla() const;
    string getPais() const;

    bool operator<(const Companhia &arl) const;

};


#endif //AIRLINE_H
