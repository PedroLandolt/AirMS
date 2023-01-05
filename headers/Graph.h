//
// Created by pland on 05/01/2023.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
public:
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        set<string> airlines;
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        int distance;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    vector<Node> nodes;

    Graph();
    explicit Graph(int nodes);
    void addEdge(int src, int dest, string airline, int weight = 1);

};


#endif //GRAPH_H
