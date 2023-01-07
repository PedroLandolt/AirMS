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

void Graph::dfs_art(int v, int index, vector<int>& num, vector<int>& low, stack<int>& s, set<int>& ap, bool first){
    nodes[v].visited = true;
    num[v] = index;
    low[v] = index;
    index++;
    bool is_ap = false;
    s.push(v);
    nodes[v].in_stack = true;
    int n_adj = 0;

    for (const auto& e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
            n_adj++;
            dfs_art(w, index, num, low, s, ap, false);
            low[v] = min(low[v], low[w]);
            if(low[w] >= num[v]) {
                is_ap = true;
                ap.insert(v);
            }
        }
        else if (nodes[w].in_stack)
            low[v] = min(low[v], num[w]);
    }
    if(is_ap && first && n_adj <= 1)
        ap.erase(v);
    s.pop();
}

set<int> Graph::getArticulationPoints() {
    set<int> articulationPoints;
    vector<int> low(n+1);
    vector<int> num(n+1);
    stack<int> s;
    for(int i = 1; i <= n; i++)
        nodes[i].visited = false;
    for(int i = 1; i <= n; i++)
        if(!nodes[i].visited){
            dfs_art(i, 0, num, low, s, articulationPoints, true);
        }
    return articulationPoints;
}

int Graph::dfs_scc(int v, int index) {
    int count = 0;
    nodes[v].num = index;
    nodes[v].low = index;
    index++;
    nodes[v].visited = true;
    nodes[v].in_stack = true;

    for(auto e : nodes[v].adj) {
        int w = e.dest;
        if(!nodes[w].visited) {
            count += dfs_scc(w, index);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        else if (nodes[w].in_stack) {
            nodes[v].low = min(nodes[v].low, nodes[w].num);
        }
    }
    if(nodes[v].num == nodes[v].low) {
        count++;
    }
    return count;
}

void Graph::dfs_scc2(int v, int index, stack<int>* node_stack, list<list<int>>* answer) {
    nodes[v].num = index;
    nodes[v].low = index;
    index++;
    nodes[v].visited = true;
    nodes[v].in_stack = true;
    node_stack->push(v);

    for(auto e : nodes[v].adj) {
        int w = e.dest;
        if(!nodes[w].visited) {
            dfs_scc2(w, index, node_stack, answer);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        else if (nodes[w].in_stack) {
            nodes[v].low = min(nodes[v].low, nodes[w].num);
        }
    }
    if(nodes[v].num == nodes[v].low) {
        list<int> scc;
        int w;
        do {
            w = node_stack->top();
            node_stack->pop();
            nodes[w].in_stack = false;
            scc.push_back(w);
        } while (w != v);
        answer->push_back(scc);
    }
}

void Graph::bfs(int a){
    for(int i = 1; i <= n; i++) {
        nodes[i].visited = false;
        nodes[i].distance = -1;
    }
    queue<int> q;
    q.push(a);
    nodes[a].visited = true;
    nodes[a].distance = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(const Edge& e : nodes[v].adj){
            int w = e.dest;
            if(!nodes[w].visited){
                nodes[w].visited = true;
                nodes[w].distance = nodes[v].distance + 1;
                q.push(w);
            }
        }
    }
}

int Graph::bfs_max_distance(int a) {
    if (!nodes[a].visited) return -1;
    for (int i=1; i<=n; i++) {
        nodes[i].visited = false;
        nodes[i].distance = -1;
    }
    queue<int> q;
    q.push(a);
    nodes[a].visited = true;
    nodes[a].distance = 0;
    int max_dist = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const auto& e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance = nodes[u].distance + 1;
                if (nodes[w].distance > max_dist) max_dist = nodes[w].distance;
            }
        }
    }
    return max_dist;
}

int Graph::diametro() {
    int max = 0;
    nodes[1].visited = true;
    for (int v = 1; v <= n; v++) {
        int d = bfs_max_distance(v);
        if (d > max) max = d;
    }
    return max;
}
