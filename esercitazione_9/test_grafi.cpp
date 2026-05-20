#include <iostream>
#include <list>
#include <set>
#include "graph_visit.hpp"

using namespace std;

int main() {
    list<int> nodi_o = {1, 2, 3, 4, 5};
    set<oriented_edge<int>> archi_orientati;
    oriented_graph<int> G_orientato(nodi_o, archi_orientati);

    G_orientato.add_edge(1, 2);
    G_orientato.add_edge(1, 3);
    G_orientato.add_edge(2, 4);
    G_orientato.add_edge(3, 4);
    G_orientato.add_edge(4, 5);
    G_orientato.add_edge(5, 1);
    G_orientato.add_edge(1, 5);

    fifo<int> q;
    oriented_graph<int> albero_bfs = graph_visit(G_orientato, 1, q);
    cout << "Albero BFS:" << endl;
    for (const auto& node : albero_bfs.V) {
        cout << node << " : ";
        for (const auto& edge : albero_bfs.adj[node]) {
            cout << edge.to() << " ";
        }
        cout << endl;
    }

    lifo<int> s;
    oriented_graph<int> albero_dfs = graph_visit(G_orientato, 1, s);
    cout << "Albero DFS:" << endl;
    for (const auto& node : albero_dfs.V) {
        cout << node << " : ";
        for (const auto& edge : albero_dfs.adj[node]) {
            cout << edge.to() << " ";
        }
        cout << endl;
    }


    list<int> nodi_uni = {1, 2, 3, 4};
    set<unidirected_edge<int>> archi_unidirected;
    unidirected_graph<int> G_unidirected(nodi_uni, archi_unidirected);

    G_unidirected.add_edge(1, 2);
    G_unidirected.add_edge(2, 3);
    G_unidirected.add_edge(3, 4);
    G_unidirected.add_edge(1, 4);

    result_djikstra ris_dijkstra = Djikstra(G_unidirected, 1);
    cout << "Distanze minime da 1:" << endl;
    for (const auto& [node, distanza] : ris_dijkstra.distanze) {
        cout << "Nodo " << node << ": " << distanza << endl;
    }

    return 0;
}