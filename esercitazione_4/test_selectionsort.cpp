#include "es_4.1.hpp"
#include <iostream>
#include <vector>
#include "randfiller.h"

using namespace std;

int main() {
    randfiller rf;
    vector<int> vec;
    
    bool sorted = false;

    for (int i=0; i<=100; i++){
        vec.resize(rand()%10000);
        rf.fill(vec, -10000, 10000);
        SelectionSort(vec);
        if (is_sorted(vec)) {
            sorted = true;
        }else{
            sorted = false;
        }
    }

    vector<string> vec1 = {"zaino", "mela", "casa", "barca", "albero", "fuoco", "gatto", "dado", "elefante", "iper"};
    SelectionSort(vec1);
    if (is_sorted(vec1)) {
        sorted = true;
    } else {
        sorted = false;
    }
    
    if (sorted) {
        return EXIT_SUCCESS;
    }
    
}