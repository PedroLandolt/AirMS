//
// Created by pland on 05/01/2023.
//

#ifndef DISTANCIAS_H
#define DISTANCIAS_H
/** dependencies */
#include <bits/stdc++.h>
using namespace std;

/** Função que calcula a distância entre dois pontos
 * @param lat1 Double com a latitude do primeiro ponto
 * @param lon1 Double com a longitude do primeiro ponto
 * @param lat2 Double com a latitude do segundo ponto
 * @param lon2 Double com a longitude do segundo ponto
 * @return Double com a distância entre os dois pontos
 * @brief Complexidade O(1)
 */
double distancia(double lat1, double lon1, double lat2, double lon2);

/** Função que calcula a distância entre dois pontos
 * @param coord1 Par de doubles com as coordenadas do primeiro ponto
 * @param coord2 Par de doubles com as coordenadas do segundo ponto
 * @return Double com a distância entre os dois pontos
 * @brief Complexidade O(1)
 */
double distancia(pair<double, double> coord1, pair<double, double> coord2);

#endif //DISTANCIAS_H
