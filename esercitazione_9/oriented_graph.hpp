#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include "oriented_edge.hpp"

using namespace std;

template<typename T>
class oriented_graph {
    public:

    map<T, set<oriented_edge<T>> > adj;
    list<T> V;
    set<oriented_edge<T>> E;
    
    oriented_graph() = default;

    oriented_graph(list<T> vertices, set<oriented_edge<T>> edges) : V(move(vertices)), E(move(edges)) {
        for (const auto& edge : E) {
            adj[edge.from()].insert(edge);
         }
} 

void add_vertex(T vertex) {
    if (find(V.begin(), V.end(), vertex) == V.end()) {
        V.push_back(vertex);
    }
}
    
set<oriented_edge<T>> neighbours(T node) {
    if (find(V.begin(),V.end(),node) != V.end()) {
        if (adj.contains(node) && !adj[node].empty()) {
            return adj[node];
         } else {
            cout << "Il nodo " << node << " non ha vicini\n";
            return set<oriented_edge<T>>();
        }
    } else {    
        cout << "Il nodo " << node << " non esiste nel grafo\n";
        return set<oriented_edge<T>>();
    }
}

void add_edge(T from, T to) {
    if ((find(V.begin(),V.end(),from) != V.end()) && (find(V.begin(),V.end(),to) != V.end())) {
        oriented_edge<T> new_edge(from, to);
        E.insert(new_edge);
        adj[new_edge.from()].insert(new_edge);
    } else {
        cout << "Uno o entrambi i nodi non esistono nel grafo\n";
    }
}

set<oriented_edge<T>> operator-(const oriented_graph& other) const {
    set<oriented_edge<T>> difference;
    for (const auto& edge : E) {
        if (!other.E.contains(edge)) {
            difference.insert(edge);
        }
    }
    return difference;
}

};
  