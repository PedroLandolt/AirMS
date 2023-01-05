#include <bits/stdc++.h>

#include "../headers/Ler.h"

using namespace std;


Ler lfile;
Graph g;


int main(){

    lfile.ler_aeroportos();
    g = Graph((int) lfile.getAeroportos().size());
    cout << "Aeroportos: " << lfile.getAeroportos().size() << endl;
    cout << "Nos: "<<g.nodes.size() << endl;
    lfile.ler_companhias();
    lfile.ler_voos(g);

    int sum_edges = 0;
    int sum_airlines = 0;

    for(const auto& nd : g.nodes){
        for(const auto& ed : nd.adj){
            sum_edges++;
            sum_airlines += ed.airlines.size();
        }
    }

    cout << "Edges: " << sum_edges << endl;
    cout << "Voos: " << sum_airlines << endl;

    return 0;
}