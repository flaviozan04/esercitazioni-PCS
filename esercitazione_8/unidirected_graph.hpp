#include "unidirected_edge.hpp"
#include <set>
#include <concepts>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

template<typename T>
class unidirected_graph {

    map<T, set<unidirected_edge<T>> > adj;
    list<T> V;
    set<unidirected_edge<T>> E;
    
public:
    unidirected_graph() = default;

    unidirected_graph(list<T> vertices, set<unidirected_edge<T>> edges) : V(move(vertices)), E(move(edges)) {
            for (const auto& edge : E) {
                adj[edge.from()].insert(edge);
             }
    } 
        
    void neighbours(const unidirected_graph& g, T node) {
        if (find(V.begin(),V.end(),node) != V.end()) {
            if (adj.contains(node) && !adj[node].empty()) {
                cout << "I vicini del nodo " << node << " sono:\n";
                for (const auto& edge : adj[node]) {
                    T neighbour = edge.to();
                    cout << neighbour << ", ";
                }
            } else {
                cout << "Il nodo " << node << " non ha vicini\n";
            }
        } else {
            cout << "Il nodo " << node << " non esiste nel grafo\n";
        }  
    }

    void add_edge(T from, T to) {
        if ((find(V.begin(),V.end(),from) != V.end()) && (find(V.begin(),V.end(),to) != V.end())) {
            unidirected_edge<T> new_edge(from, to);
            E.insert(new_edge);
            adj[new_edge.from()].insert(new_edge);
            adj[new_edge.to()].insert(new_edge);
        } else {
            cout << "Uno o entrambi i nodi non esistono nel grafo\n";
        }
    }

    void all_edges() const {
        if (E.empty()) {
            cout << "Il grafo non ha archi\n";
        }else{
            for (const auto& edge : E) {
                cout << edge << "\n";
            }
        }
    }

    void all_nodes() const {
        if (V.empty()) {
            cout << "Il grafo non ha nodi\n";
        }else{
            for (const auto& i : V) {
                cout << i << "\n";
            }
        }
    }

    void edge_number(unidirected_edge<T> edge) {
        if (E.empty()) {
            cout << "Il grafo non ha archi\n";
            return;
        }
    
        auto itor = E.find(edge);
    
        if (itor != E.end()) {
            auto number = distance(E.begin(), itor) + 1;
            
            cout << "Il numero dell'arco " << edge << " è: " << number << "\n";
        } else {
            cout << "L'arco " << edge << " non è presente nel grafo\n";
        }
    }

    void edge_at(size_t number) {
        if (E.empty()) {
            cout << "Il grafo non ha archi" << "\n";
        }
        
        if (number >= 1 && number <= E.size()) {
            auto itor = next(E.begin(), number - 1);
            cout << "l'arco in posizione" << number << "è" << *itor << "\n"; 
        } else {
            cout << "Numero dell'arco non valido" << "\n";
        }
    }

    set<unidirected_edge<T>> operator-(const unidirected_graph& other) const {
        set<unidirected_edge<T>> difference;
        for (const auto& edge : E) {
            if (!other.E.contains(edge)) {
                difference.insert(edge);
            }
        }
        return difference;
    }

};