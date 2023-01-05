#include <bits/stdc++.h>
#include "../headers/Graph.h"


Graph::Graph() {
    n = 0;
}

Graph::Graph(int num) : n(num), nodes(num+1) {
}

void Graph::addEdge(int src, int dest, string airline, int weight) {

    if (src<1 || src>n || dest<1 || dest>n) return;

    for (Edge &e : nodes[src].adj)
        if (e.dest == dest) {
            e.airlines.insert(airline);
            return;
        }

    nodes[src].adj.push_back({dest, weight, {airline}});
}


