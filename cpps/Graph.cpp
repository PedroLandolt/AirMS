#include <bits/stdc++.h>
#include "../headers/Graph.h"


Graph::Graph() {
    n = 0;
}

Graph::Graph(int num) : n(num), nodes(num+1) {
}

void Graph::addEdge(int src, int dest, string companhia, int weight) {

    if (src<1 || src>n || dest<1 || dest>n) return;

    for (Edge &e : nodes[src].adj)
        if (e.dest == dest) {
            e.companhias.insert(companhia);
            return;
        }

    nodes[src].adj.push_back({dest, weight, {companhia}});
}

vector<int> Graph::bfs_me(int origem, int destino) {

    for(int i = 1; i <= n; i++){
        nodes[i].visited = false;
        nodes[i].distance = -1;
    }

    vector<int> caminho(n+1);
    queue<int> q;
    q.push(origem);
    nodes[origem].visited = true;
    nodes[origem].distance = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(const Edge& e : nodes[v].adj){
            int w = e.dest;
            if(!nodes[w].visited){
                nodes[w].visited = true;
                nodes[w].distance = nodes[v].distance + 1;
                q.push(w);
                caminho[w] = v;
            }
            else if(nodes[w].distance == nodes[v].distance + 1){
                caminho[w] = v;
            }
        }
    }

    int min_dist = nodes[destino].distance;

    vector<int> res;
    if(min_dist == -1) return res;

    for(int i = destino; i != origem; i = caminho[i]){
        res.push_back(i);
    }

    return res;

}

vector<int> Graph::bfs_me_companhias(int origem, int destino, const set<string>& companhias) {

    for(int i = 1; i <= n; i++){
        nodes[i].visited = false;
        nodes[i].distance = -1;
    }

    vector<int> caminho(n+1);
    queue<int> q;
    q.push(origem);
    nodes[origem].visited = true;
    nodes[origem].distance = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(const Edge& e : nodes[v].adj){
            int w = e.dest;
            set<string> inter_comp;
            set_intersection(companhias.begin(), companhias.end(), e.companhias.begin(), e.companhias.end(), inserter(inter_comp, inter_comp.begin()));
            if(inter_comp.empty()) continue;
            if(!nodes[w].visited){
                nodes[w].visited = true;
                nodes[w].distance = nodes[v].distance + 1;
                q.push(w);
                caminho[w] = v;
            }
            else if(nodes[w].distance == nodes[v].distance + 1){
                caminho[w] = v;
            }
        }
    }

    int min_dist = nodes[destino].distance;

    vector<int> res;
    if(min_dist == -1) return res;

    for(int i = destino; i != origem; i = caminho[i]){
        res.push_back(i);
    }

    return res;

}


