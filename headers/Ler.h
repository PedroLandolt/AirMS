//
// Created by pland on 05/01/2023.
//

#ifndef READ_H
#define READ_H

#include <bits/stdc++.h>
#include "../headers/Aeroporto.h"
#include "../headers/Companhia.h"
#include "../headers/Distancias.h"
#include "../headers/Graph.h"


//Struct hash pair para verficar se dois aeroportos têm coods iguais
struct hashpair{
    size_t operator()(const pair<double, double> &p) const {
        auto hash1 = hash<double>{}(p.first);
        auto hash2 = hash<double>{}(p.second);
        return hash1 ^ hash2;
    }
};

struct hashpairstring{
    size_t operator()(const pair<string, string> &p) const {
        auto hash1 = hash<string>{}(p.first);
        auto hash2 = hash<string>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Ler {

    unordered_map<string, int> aeroportos_codigos;
    unordered_map<int, Aeroporto> aeroportos;
    unordered_map<pair<double, double>, int, hashpair> aeroportos_coords;
    unordered_map<string, unordered_set<int>> aeroportos_companhias;

    unordered_map<pair<string, string>, string, hashpairstring> chegada_partida_companhia;

    unordered_map<string, int> companhias_codigos;
    unordered_map<int, Companhia> companhias;

    unordered_map<string, vector<int>> cidades_aeroportos;
    unordered_map<string, vector<int>> paises_aeroportos;
    unordered_map<string, vector<int>> companhias_aeroportos;
    unordered_map<string, unordered_set<string>> pais_cidades;

    unordered_map<int, pair<string,string>> id_pais_cidade;
    unordered_map<pair<string,string>, vector<int>, hashpairstring> pais_cidade_aeroportos;

public:

    void ler_aeroportos();
    void ler_companhias();
    void ler_voos(Graph &gh);

    unordered_map<string, int> getAeroportosCodigos() const;
    unordered_map<int, Aeroporto> getAeroportos() const;
    unordered_map<pair<double, double>, int, hashpair> getAeroportosCoords() const;
    unordered_map<string, unordered_set<int>> getAeroportosCompanhias() const;

    unordered_map<pair<string, string>, string, hashpairstring> getChegadaPartidaCompanhia() const;

    unordered_map<string, int> getCompanhiasCodigos() const;
    unordered_map<int, Companhia> getCompanhias() const;

    unordered_map<string, vector<int>> getCidadesAeroportos() const;
    unordered_map<string, vector<int>> getPaisesAeroportos() const;
    unordered_map<string, vector<int>> getCompanhiasAeroportos() const;
    unordered_map<string, unordered_set<string>> getPaisCidades() const;

    unordered_map<int, pair<string,string>> getIdPaisCidade() const;
    unordered_map<pair<string,string>, vector<int>, hashpairstring> getPaisCidadeAeroportos() const;

};


#endif //READ_H
