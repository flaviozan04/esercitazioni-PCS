#include "unidirected_graph.hpp"

using namespace std;

int main() {
    list<int> nodes = {1, 2, 3, 4, 5};
    set<unidirected_edge<int>> edges1 = { {1, 2}, {2, 3} };
    set<unidirected_edge<int>> edges2 = { {1, 2}, {4, 5} };

    unidirected_graph<int> g1(nodes, edges1);
    unidirected_graph<int> g2(nodes, edges2);

    // Test differenza tra grafi
    set<unidirected_edge<int>> diff = g1 - g2;
    if (diff.size() != 1 || !diff.contains(unidirected_edge<int>(2, 3))) {
        return EXIT_FAILURE;
    }

    // Test add_edge
    g1.add_edge(4, 5);
    set<unidirected_edge<int>> diff_after = g1 - g2;
    if (diff_after.contains(unidirected_edge<int>(4, 5))) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}