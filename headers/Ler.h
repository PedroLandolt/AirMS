//
// Created by pland on 05/01/2023.
//

#ifndef READ_H
#define READ_H
/** dependencies */
#include <bits/stdc++.h>
#include "../headers/Aeroporto.h" /** O header 'Aeroporto.h' contém definições usadas neste header */
#include "../headers/Companhia.h" /** O header 'Companhia.h' contém definições usadas neste header */
#include "../headers/Distancias.h" /** O header 'Distancias.h' contém definições usadas neste header */
#include "../headers/Graph.h" /** O header 'Graph.h' contém definições usadas neste header */


/** @brief Struct que permite usar pares de doubles como chave de um unordered_map
 *Contém um operador () que permite garantir que os elementos são diferentes
 */
struct hashpair{
    size_t operator()(const pair<double, double> &p) const {
        auto hash1 = hash<double>{}(p.first);
        auto hash2 = hash<double>{}(p.second);
        return hash1 ^ hash2;
    }
};

/** @brief Struct que permite usar pares de strings como chave de um unordered_map
 *Contém um operador () que permite garantir que os elementos são diferentes
 */
struct hashpairstring{
    size_t operator()(const pair<string, string> &p) const {
        auto hash1 = hash<string>{}(p.first);
        auto hash2 = hash<string>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Ler {

    /** Unordered_map que associa o código de um aeroporto ao seu índice no vetor de aeroportos */
    unordered_map<string, int> aeroportos_codigos;

    /** Unordered_map que associa o índice de um aeroporto ao seu objeto Aeroporto */
    unordered_map<int, Aeroporto> aeroportos;

    /** Unordered_map que associa as coordenadas de um aeroporto ao seu índice no vetor de aeroportos */
    unordered_map<pair<double, double>, int, hashpair> aeroportos_coords;

    /** Unordered_map que associa o código de uma companhia aérea ao conjunto de índices dos aeroportos que a mesma serve */
    unordered_map<string, unordered_set<int>> aeroportos_companhias;

    /** Unordered_map que associa o par de códigos de aeroportos de partida e chegada a um código de companhia aérea */
    unordered_map<pair<string, string>, string, hashpairstring> chegada_partida_companhia;

    /** Unordered_map que associa o código de uma companhia aérea ao seu índice no vetor de companhias aéreas */
    unordered_map<string, int> companhias_codigos;

    /** Unordered_map que associa o índice de uma companhia aérea ao seu objeto Companhia */
    unordered_map<int, Companhia> companhias;

    /** Unordered_map que associa o nome de uma cidade ao vetor de índices dos aeroportos dessa cidade */
    unordered_map<string, vector<int>> cidades_aeroportos;

    /** Unordered_map que associa o nome de um país ao vetor de índices dos aeroportos desse país */
    unordered_map<string, vector<int>> paises_aeroportos;

    /** Unordered_map que associa o código de uma companhia aérea ao vetor de índices dos aeroportos que a mesma serve */
    unordered_map<string, vector<int>> companhias_aeroportos;

    /** Unordered_map que associa o nome de um país ao conjunto de nomes das cidades desse país */
    unordered_map<string, unordered_set<string>> pais_cidades;

    /** Unordered_map que associa o índice de um aeroporto ao par de nomes do país e da cidade desse aeroporto */
    unordered_map<int, pair<string,string>> id_pais_cidade;

    /** Unordered_map que associa o par de nomes do país e da cidade de um aeroporto ao vetor de índices dos aeroportos dessa cidade desse país */
    unordered_map<pair<string,string>, vector<int>, hashpairstring> pais_cidade_aeroportos;

public:

    /** @brief Função que lê os aeroportos do ficheiro 'airports.csv' e os guarda no vetor de aeroportos
 * @brief Complexidade: O(n) onde n é o número de aeroportos
 */
    void ler_aeroportos();

    /** @brief Função que lê as companhias aéreas do ficheiro 'airlines.csv' e as guarda no vetor de companhias aéreas
 * @brief Complexidade: O(n) onde n é o número de companhias aéreas
 */
    void ler_companhias();

    /** @brief Função que lê os voos do ficheiro 'flights.csv' e os guarda no grafo de voos
 * @param gh Grafo de voos
 * @brief Complexidade: O(n) onde n é o número de voos
 */
    void ler_voos(Graph &gh);

    /** Getter
 * @return unordered_map que associa o código de um aeroporto ao seu índice no vetor de aeroportos
 * @brief Complexidade: O(1)
 */
    unordered_map<string, int> getAeroportosCodigos() const;

    /** Getter
 * @return unordered_map que associa o índice de um aeroporto ao seu objeto Aeroporto
 * @brief Complexidade: O(1)
 */
    unordered_map<int, Aeroporto> getAeroportos() const;

    /** Getter
 * @return unordered_map que associa as coordenadas de um aeroporto ao seu índice no vetor de aeroportos
 * @brief Complexidade: O(1)
 */
    unordered_map<pair<double, double>, int, hashpair> getAeroportosCoords() const;

    /** Getter
 * @return unordered_map que associa o código de uma companhia aérea ao conjunto de índices dos aeroportos que a mesma serve
 * @brief Complexidade: O(1)
 */
    unordered_map<string, unordered_set<int>> getAeroportosCompanhias() const;

    /** Getter
 * @return unordered_map que associa o par de códigos de aeroportos de partida e chegada a um código de companhia aérea
 * @brief Complexidade: O(1)
 */
    unordered_map<pair<string, string>, string, hashpairstring> getChegadaPartidaCompanhia() const;

    /** Getter
 * @return unordered_map que associa o código de uma companhia aérea ao seu índice no vetor de companhias aéreas
 * @brief Complexidade: O(1)
 */
    unordered_map<string, int> getCompanhiasCodigos() const;

    /** Getter
 * @return unordered_map que associa o índice de uma companhia aérea ao seu objeto Companhia
 * @brief Complexidade: O(1)
 */
    unordered_map<int, Companhia> getCompanhias() const;

    /** Getter
 * @return unordered_map que associa o nome de uma cidade ao vetor de índices dos aeroportos dessa cidade
 * @brief Complexidade: O(1)
 */
    unordered_map<string, vector<int>> getCidadesAeroportos() const;

    /** Getter
 * @return unordered_map que associa o nome de um país ao vetor de índices dos aeroportos desse país
 * @brief Complexidade: O(1)
 */
    unordered_map<string, vector<int>> getPaisesAeroportos() const;

    /** Getter
 * @return unordered_map que associa o código de uma companhia aérea ao vetor de índices dos aeroportos que a mesma serve
 * @brief Complexidade: O(1)
 */
    unordered_map<string, vector<int>> getCompanhiasAeroportos() const;

    /** Getter
 * @return unordered_map que associa o nome de um país ao conjunto de nomes das cidades desse país
 * @brief Complexidade: O(1)
 */
    unordered_map<string, unordered_set<string>> getPaisCidades() const;

    /** Getter
 * @return unordered_map que associa o índice de um aeroporto ao par de nomes do país e da cidade desse aeroporto
 * @brief Complexidade: O(1)
 */
    unordered_map<int, pair<string,string>> getIdPaisCidade() const;

    /** Getter
 * @return unordered_map que associa o par de nomes do país e da cidade de um aeroporto ao vetor de índices dos aeroportos dessa cidade desse país
 * @brief Complexidade: O(1)
 */
    unordered_map<pair<string,string>, vector<int>, hashpairstring> getPaisCidadeAeroportos() const;

};


#endif //READ_H
