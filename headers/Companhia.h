//
// Created by pland on 05/01/2023.
//

#ifndef AIRLINE_H
#define AIRLINE_H
/** dependencies */
#include <bits/stdc++.h>

using namespace std;

class Companhia {

    /** String com o código da companhia*/
    string codigo;

    /** String com o nome da companhia*/
    string nome;

    /** String com a sigla da companhia*/
    string sigla;

    /** String com o país de origem da companhia*/
    string pais;

public:

    /** Constructor
 * @param codigo String com o código da companhia
 * @param nome String com o nome da companhia
 * @param sigla String com a sigla da companhia
 * @param pais String com o país de origem da companhia
 * @brief Complexidade O(1)
 */
    Companhia(string codigo, string nome, string sigla, string pais);

    /** Getter
 * @return String com o código da companhia
 * @brief Complexidade O(1)
 */
    string getCodigo() const;

    /** Getter
 * @return String com o nome da companhia
 * @brief Complexidade O(1)
 */
    string getNome() const;

    /** Getter
 * @return String com a sigla da companhia
 * @brief Complexidade O(1)
 */
    string getSigla() const;

    /** Getter
 * @return String com o país de origem da companhia
 * @brief Complexidade O(1)
 */
    string getPais() const;

    /** Operator Overload para comparar objetos do tipo Companhia
 * @param arl Companhia
 * @return True se o código da companhia for menor que o código da companhia passada por parâmetro
 * @return False caso contrário
 * @brief Complexidade O(1)
 */
    bool operator<(const Companhia &arl) const;

};


#endif //AIRLINE_H
