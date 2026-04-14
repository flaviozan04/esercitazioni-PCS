#include "es_4.1.hpp"
#include <iostream>
#include <vector>
#include "randfiller.h"
#include <thread>
#include <chrono>
#include "timecounter.h"

int main() {
    randfiller rf;
    vector<int> vec;
    timecounter tc; 

    for (int n = 2; n<=13; n++) {
        
        vec.resize(pow(2,n));
        rf.fill(vec, 0, 100);
        vector<int> vec1 = vec;
        vector<int> vec2 = vec;
        vector<int> vec3 = vec;
        cout << "Vettore di dimensione: " << vec.size() << "\n";
        cout << "\n"; 
        
        tc.tic();
        BubbleSort(vec);
        double secs = tc.toc();
        cout << "Tempo impiegato da BubbleSort: " << secs << " secondi\n";

        tc.tic();
        SelectionSort(vec1);
        double secs1 = tc.toc();
        cout << "Tempo impiegato da SelectionSort: " << secs1 << " secondi\n";

        tc.tic();
        InsertionSort(vec2);
        double secs2 = tc.toc();
        cout << "Tempo impiegato da InsertionSort: " << secs2 << " secondi\n";

        tc.tic();
        sort(vec3.begin(), vec3.end());
        double secs3 = tc.toc();
        cout << "Tempo impiegato da sort: " << secs3 << " secondi\n"; 
        cout << "\n"; 
    }  
}