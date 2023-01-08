//
// Created by pland on 05/01/2023.
//

#ifndef GRAPH_H
#define GRAPH_H
/** dependencies */
#include <list>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
public:
    /**
     * @brief Struct que representa uma aresta do grafo
     * Contém o vértice de destino, o peso da aresta e um set de companhias aéreas que realizam voos nessa aresta
     */
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        set<string> companhias;
    };

    /**
     * @brief Struct que representa um nó do grafo
     * Contém uma lista de arestas que saem desse nó
     * um booleano que indica se o nó já foi visitado
     * um inteiro que indica a distância do nó ao nó de origem da pesquisa
     */

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        int distance;
        bool in_stack;
        int num;
        int low;
    };

    /** Número de nós */
    int n;

    /** vector de nós */
    vector<Node> nodes;

    /** Default Constructor
 * @brief Complexidade O(1)
 */
    Graph();

    /** Constructor
 * @param nodes Número de nós
 * @brief Complexidade O(1)*/
    explicit Graph(int nodes);

    /** Função que adiciona uma aresta ao grafo
 * @param src Nó de origem
 * @param dest Nó de destino
 * @param companhia Companhia aérea que realiza o voo
 * @param weight Peso da aresta, 1 por omissão
 * @brief Complexidade O(1)
 */
    void addEdge(int src, int dest, string companhia, int weight = 1);

    //dfs e bfs
    /** Função que realiza uma pesquisa em largura no grafo e retorna um vetor com o caminho com menos escalas entre dois nós
 * @param origem Nó de origem
 * @param destino Nó de destino
 * @return Vector com os caminhos com menos escalas realizadas entre o nó de origem e o nó de destino
 * @brief Complexidade O(|V|+|E|)
 */
    vector<int> bfs_me(int origem, int destino);

    /** Função que realiza uma pesquisa em largura no grafo e retorna um vetor com o caminho com menos escalas entre dois nós, passando por companhias aéreas específicas
 * @param origem Nó de origem
 * @param destino Nó de destino
 * @param companhias Set de companhias aéreas
 * @return Vector com os caminhos com menos escalas realizadas entre o nó de origem e o nó de destino
 * @brief Complexidade O(|V|+|E|)
 */
    vector<int> bfs_me_companhias(int origem, int destino, const set<string>& companhias);

    /** Função que realiza uma pesquisa em profundidade no grafo e retorna um set com os pontos de articulação
 * @param v Nó de origem
 * @param index Número de nós visitados
 * @param num Vector com o número de nós visitados
 * @param low Vector com o menor número de nós visitados
 * @param s Stack com os nós visitados
 * @param ap Set com os nós de articulação
 * @param first Booleano que indica se é a primeira chamada à função
 * @brief Complexidade O(|V|+|E|)
 */
    void dfs_art(int v, int index, vector<int>& num, vector<int>& low, stack<int>& s, set<int>& ap, bool first);

    /** Função que retorna um set com os pontos de articulação
 * @return Set com os pontos de articulação
 * @brief Complexidade O(|V|+|E|)*/
    set<int> getArticulationPoints();

    /** Função que realiza uma pesquisa em profundidade no grafo e retorna um inteiro com o número de componentes fortemente conexos
 * @param v Nó de origem
 * @param index Número de nós visitados
 * @return Número de componentes fortemente conexos
 * @brief Complexidade O(|V|+|E|)
 */
    int dfs_scc(int v, int index);

    /** Função que realiza uma pesquisa em profundidade no grafo e retorna um inteiro com o número de componentes fortemente conexos
 * @param v Nó de origem
 * @param index Número de nós visitados
 * @param node_stack Stack com os nós visitados
 * @param answer Lista de listas com os nós visitados
 * @brief Complexidade O(|V|+|E|)
 */
    void dfs_scc2(int v, int index, stack<int> *node_stack, list<list<int>> *answer);

    /** Função que realiza uma pesquisa em largura no grafo
 * @param a Nó de origem
 * @brief Complexidade O(|V|+|E|)
 */
    void bfs(int a);

    /** Função que retorna o diâmetro do grafo
 * @return Diâmetro do grafo
 * @brief Complexidade O(|V|+|E|)
 */
    int diametro();

    /** Função que realiza uma pesquisa em largura no grafo e retorna a distância máxima entre um nó e os restantes nós
 * @param a Nó de origem
 * @return Distância máxima entre um nó e os restantes nós
 * @brief Complexidade O(|V|+|E|)
 */
    int bfs_max_distance(int a);

};


#endif //GRAPH_H
