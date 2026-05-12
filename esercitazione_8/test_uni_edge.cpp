#include "unidirected_edge.hpp"
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(NULL))); //Mi sono aiutato con AI per capire come inizializzare il generatore di numeri casuali

    for (int i = 0; i < 1000; i++) {
        int from = rand() % 1000;
        int to = rand() % 1000;

        unidirected_edge<int> edge1(from, to);
        unidirected_edge<int> edge2(to, from);

        if (!(edge1 == edge2)) {
            return EXIT_FAILURE;
        }

        unidirected_edge<int> edge_small(-1, -1);
        if (!(edge_small < edge1)) {
            return EXIT_FAILURE; 
        }
    }

    return EXIT_SUCCESS; 
}