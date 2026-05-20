#include "fifo.hpp"
#include "lifo.hpp"
#include "oriented_graph.hpp"
#include "unidirected_graph.hpp"

using namespace std;

template <typename T>
oriented_graph<T> bfsG(oriented_graph<T> G, T radice) {
    oriented_graph<T> visited;
    fifo<pair<T, T>> queue; 
    
    queue.put({radice, radice});
    
    while(!queue.empty()) {
        auto [node, padre] = queue.get();
        
        if(find(visited.V.begin(), visited.V.end(), node) == visited.V.end()) {
            visited.add_vertex(node);
            
            if (node != radice) {
                visited.add_edge(padre, node);
            }
            
            for(const auto& edge : G.adj[node]) {
                queue.put({edge.to(), node}); 
            }
        }
    }
    return visited;
}

template <typename T>
void dfs_ricorsione(oriented_graph<T>& G, lifo<T>& stack, oriented_graph<T>& visited) {
    if (stack.empty()) {
        return;
    }

    T node = stack.get();

    if (find(visited.V.begin(), visited.V.end(), node) == visited.V.end()) {
        visited.add_vertex(node);
        
        if(G.adj.contains(node)) {
            vector<oriented_edge<int>> vicini;
            for (const auto& edge : G.adj[node]) {
                vicini.push_back(edge);
            }

            for (int i = vicini.size() - 1; i >= 0; i--) {
                stack.put(vicini[i].to());
            }
        }
    }
}

template <typename T>
void dfs_ricorsione(oriented_graph<T>& G, lifo<pair<T, T>>& stack, oriented_graph<T>& visited) {
    if (stack.empty()) {
        return;
    }

    auto [node, padre] = stack.get();

    if (find(visited.V.begin(), visited.V.end(), node) == visited.V.end()) {
        visited.add_vertex(node);
        
        if (node != padre) {
            visited.add_edge(padre, node);
        }
        
        if(G.adj.contains(node)) {
            vector<oriented_edge<T>> vicini;
            for (const auto& edge : G.adj[node]) {
                vicini.push_back(edge);
            }

            for (int i = vicini.size() - 1; i >= 0; i--) {
                stack.put({vicini[i].to(), node}); 
            }
        }
    }
    dfs_ricorsione(G, stack, visited);
}

template <typename T>
oriented_graph<T> dfsG(oriented_graph<T> G, T radice) {
    oriented_graph<T> visited;
    lifo<pair<T, T>> stack;
    
    if (find(G.V.begin(), G.V.end(), radice) == G.V.end()) {
        cout << "La radice non esiste nel grafo." << endl;
        return visited;
    }

    stack.put({radice, radice});
    dfs_ricorsione(G, stack, visited);

    return visited;
}

template <typename T>
oriented_graph<T> graph_visit(oriented_graph<T> G, T radice, fifo<T> container){
    oriented_graph<T> tree = bfsG(G, radice);
    return tree;
}

template <typename T>
oriented_graph<T> graph_visit(oriented_graph<T> G, int radice, lifo<T> container){
    oriented_graph<T> tree = dfsG(G, radice);
    return tree;
}

class result_djikstra {
    public:
    map<int, int> distanze;
    map<int, int> predecessori;
};

template <typename T>
result_djikstra Djikstra(unidirected_graph<T> G, T radice) {
    result_djikstra result;
    for (const auto& node : G.V) {
        result.distanze[node] = 1000000; //Ho usato un numero molto grande per rappresentare l'infinito come suggerito a esercitazione
        result.predecessori[node] = -1;
    }
    result.predecessori[radice] = radice;
    result.distanze[radice] = 0;

    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> queue;
    for(const auto& node : G.V) {
        queue.push({result.distanze[node], node}); //La coda con priorità ordina i nodi in base al primo elemento, quindi alla distanza
    }
    while(!queue.empty()) {
        auto [p, u] = queue.top();
        queue.pop();
    
        for(const auto& edge : G.adj[u]) {
            int v = (edge.from() == u) ? edge.to() : edge.from();
    
            if(result.distanze[u] + 1 < result.distanze[v]) {
                result.distanze[v] = result.distanze[u] + 1;
                result.predecessori[v] = u;
                queue.push({result.distanze[v], v});
        }
    }
}
    
    return result;

}