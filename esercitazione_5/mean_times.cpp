#include "sorts.hpp"
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
    vector<vector<int>> vecs(100);

    for (int i=0; i<vecs.size(); i++){
        vec.resize(rand()%10000);
        rf.fill(vec, -10000, 10000);
        vecs[i] = vec;
        }
    
    vector<vector<int>> vecs1 = vecs, vecs2 = vecs, vecs3 = vecs, vecs4 = vecs; 

    tc.tic();
    for (int i=0; i<vecs.size(); i++) {
        BubbleSort(vecs[i]);
    }
    double secs = tc.toc();

    double mean_bubble = secs / vecs.size();
    cout << "Tempo medio di BubbleSort: " << mean_bubble << " secondi" << endl;


    tc.tic();
    for (int i=0; i<vecs1.size(); i++) {
        SelectionSort(vecs1[i]);
    }
    double secs1 = tc.toc();

    double mean_selec = secs1 / vecs1.size();
    cout << "Tempo medio di SelectionSort: " << mean_selec << " secondi" << endl;


    tc.tic();
    for (int i=0; i<vecs2.size(); i++) {
        InsertionSort(vecs2[i]);
    }
    double secs2 = tc.toc();

    double mean_inser = secs2 / vecs2.size();
    cout << "Tempo medio di InsertionSort: " << mean_inser << " secondi" << endl;


    tc.tic();
    for (int i=0; i<vecs3.size(); i++) {
        MergeSort(vecs3[i],0,vecs3[i].size() - 1);
    }
    double secs3 = tc.toc();    

    double mean_merge = secs3 / vecs3.size();
    cout << "Tempo medio di MergeSort: " << mean_merge << " secondi" << endl;


    tc.tic();
    for (int i=0; i<vecs4.size(); i++) {
        QuickSort(vecs4[i],0,vecs4[i].size() - 1);
    }
    double secs4 = tc.toc();

    double mean_quick = secs4 / vecs4.size();
    cout << "Tempo medio di QuickSort: " << mean_quick << " secondi" << endl;

}