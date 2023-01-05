//
// Created by pland on 05/01/2023.
//

#ifndef AED_PROJETO_2_AEROPORTO_H
#define AED_PROJETO_2_AEROPORTO_H

#include <string>
using namespace std;

class Aeroporto {

    string codigo;
    string nome;
    string cidade;
    string pais;
    double latitude;
    double longitude;

public:

    Aeroporto(string codigo, string nome, string cidade, string pais, double latitude, double longitude);

    string getCodigo() const;
    string getNome() const;
    string getCidade() const;
    string getPais() const;
    double getLatitude() const;
    double getLongitude() const;

};


#endif //AED_PROJETO_2_AEROPORTO_H
