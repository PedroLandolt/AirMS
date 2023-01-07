//
// Created by pland on 05/01/2023.
//

#include "Ler.h"
#include <bits/stdc++.h>

using namespace std;

void Ler::ler_aeroportos() {

    ifstream aeroporto_file("../data/airports.csv");

    string line;
    int i = 1;
    getline(aeroporto_file, line);
    while (getline(aeroporto_file, line)) {
        istringstream ss(line);
        string codigo, nome, cidade, pais;
        double latitude, longitude;
        getline(ss, codigo, ',');
        getline(ss, nome, ',');
        getline(ss, cidade, ',');
        getline(ss, pais, ',');
        ss >> latitude;
        ss.ignore();
        ss >> longitude;


        Aeroporto aeroporto(codigo, nome, cidade, pais, latitude, longitude);

        aeroportos_codigos.insert({codigo, i});
        aeroportos.insert({i, aeroporto});
        aeroportos_coords.insert({{latitude, longitude}, i});

        transform(cidade.begin(), cidade.end(), cidade.begin(), ::toupper);
        transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

        pair<string,string> pais_cidade = make_pair(pais,cidade);
        id_pais_cidade.insert({i, pais_cidade});

        if(pais_cidade_aeroportos.find(pais_cidade) == pais_cidade_aeroportos.end()){
            vector<int> aerop_city;
            aerop_city.push_back(i);
            pais_cidade_aeroportos.insert({pais_cidade, aerop_city});
        }
        else{
            pais_cidade_aeroportos.at(pais_cidade).push_back(i);
        }


        if (cidades_aeroportos.find(cidade) == cidades_aeroportos.end()) {
            vector<int> aeroportos_cidade;
            aeroportos_cidade.push_back(i);
            cidades_aeroportos.insert({cidade, aeroportos_cidade});
        } else {
            cidades_aeroportos.at(cidade).push_back(i);
        }

        if (paises_aeroportos.find(pais) == paises_aeroportos.end()) {
            vector<int> aeroportos_pais;
            aeroportos_pais.push_back(i);
            paises_aeroportos.insert({pais, aeroportos_pais});
        } else {
            paises_aeroportos.at(pais).push_back(i);
        }

        if (pais_cidades.find(pais) == pais_cidades.end()) {
            unordered_set<string> cidades_pais;
            cidades_pais.insert(cidade);
            pais_cidades.insert({pais, cidades_pais});
        } else {
            pais_cidades.at(pais).insert(cidade);
        }

        i++;
    }
}


void Ler::ler_companhias() {

    ifstream companhia_file("../data/airlines.csv");

    string line;
    int i = 1;
    getline(companhia_file, line);
    while (getline(companhia_file, line)) {
        istringstream ss(line);
        string codigo, nome, sigla, pais;
        getline(ss, codigo, ',');
        getline(ss, nome, ',');
        getline(ss, sigla, ',');
        getline(ss, pais);

        Companhia companhia(codigo, nome, sigla, pais);

        companhias_codigos.insert({codigo, i});
        companhias.insert({i, companhia});

        i++;
    }
}


void Ler::ler_voos(Graph &gh) {

    ifstream voos_file("../data/flights.csv");

    string line;
    getline(voos_file, line);
    while (getline(voos_file, line)) {
        istringstream ss(line);
        string codigo_aeroporto_origem, codigo_aeroporto_destino, codigo_companhia;

        getline(ss, codigo_aeroporto_origem, ',');
        getline(ss, codigo_aeroporto_destino, ',');
        getline(ss, codigo_companhia);

        Aeroporto aeroporto_origem = aeroportos.at(aeroportos_codigos.at(codigo_aeroporto_origem));
        Aeroporto aeroporto_destino = aeroportos.at(aeroportos_codigos.at(codigo_aeroporto_destino));

        int dist = (int) distancia(aeroporto_origem.getLatitude(), aeroporto_origem.getLongitude(),
                                   aeroporto_destino.getLatitude(), aeroporto_destino.getLongitude());

        gh.addEdge(aeroportos_codigos.at(codigo_aeroporto_origem), aeroportos_codigos.at(codigo_aeroporto_destino),
                  codigo_companhia, dist);

        if (companhias_aeroportos.find(codigo_companhia) == companhias_aeroportos.end()) {
            vector<int> aeroportos_companhia;
            aeroportos_companhia.push_back(aeroportos_codigos.at(codigo_aeroporto_origem));
            companhias_aeroportos.insert({codigo_companhia, aeroportos_companhia});
        }
        else {
            companhias_aeroportos.at(codigo_companhia).push_back(aeroportos_codigos.at(codigo_aeroporto_origem));
        }

        if(aeroportos_companhias.find(codigo_aeroporto_origem) == aeroportos_companhias.end()){
            unordered_set<int> companhias_aeroporto;
            companhias_aeroporto.insert(companhias_codigos.at(codigo_companhia));
            aeroportos_companhias.insert({codigo_aeroporto_origem, companhias_aeroporto});
        }
        else{
            aeroportos_companhias.at(codigo_aeroporto_origem).insert(companhias_codigos.at(codigo_companhia));
        }

        chegada_partida_companhia.insert({make_pair(codigo_aeroporto_origem, codigo_aeroporto_destino), codigo_companhia});

    }
}



unordered_map<string, int> Ler::getAeroportosCodigos() const {
    return aeroportos_codigos;
}

unordered_map<int, Aeroporto> Ler::getAeroportos() const {
    return aeroportos;
}

unordered_map<pair<double, double>, int, hashpair> Ler::getAeroportosCoords() const {
    return aeroportos_coords;
}

unordered_map<string, int> Ler::getCompanhiasCodigos() const {
    return companhias_codigos;
}

unordered_map<int, Companhia> Ler::getCompanhias() const {
    return companhias;
}

unordered_map<string, vector<int>> Ler::getCidadesAeroportos() const {
    return cidades_aeroportos;
}

unordered_map<string, vector<int>> Ler::getPaisesAeroportos() const {
    return paises_aeroportos;
}

unordered_map<string, vector<int>> Ler::getCompanhiasAeroportos() const {
    return companhias_aeroportos;
}

unordered_map<string, unordered_set<string>> Ler::getPaisCidades() const {
    return pais_cidades;
}

unordered_map<string, unordered_set<int>> Ler::getAeroportosCompanhias() const {
    return aeroportos_companhias;
}

unordered_map<int, pair<string, string>> Ler::getIdPaisCidade() const {
    return id_pais_cidade;
}

unordered_map<pair<string, string>, vector<int>, hashpairstring> Ler::getPaisCidadeAeroportos() const {
    return pais_cidade_aeroportos;
}

unordered_map<pair<string, string>, string, hashpairstring> Ler::getChegadaPartidaCompanhia() const {
    return chegada_partida_companhia;
}






