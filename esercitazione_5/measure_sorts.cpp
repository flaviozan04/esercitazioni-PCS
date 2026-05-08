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
    vector<double> bubble_time(12), selection_time(12), insertion_time(12), sort_time(12), merge_time(12), quick_time(12);

    for (int n = 1; n<=13; n++) {
        
        vec.resize(pow(2,n));
        rf.fill(vec, 0, 100);
        vector<int> vec1 = vec, vec2 = vec, vec3 = vec,vec4 = vec, vec5 = vec;
        
        tc.tic();
        BubbleSort(vec);
        double secs = tc.toc();
        bubble_time[n-1] = secs;

        tc.tic();
        SelectionSort(vec1);
        double secs1 = tc.toc();
        selection_time[n-1] = secs1;

        tc.tic();
        InsertionSort(vec2);
        double secs2 = tc.toc();
        insertion_time[n-1] = secs2;

        tc.tic();
        sort(vec3.begin(), vec3.end());
        double secs3 = tc.toc();
        sort_time[n-1] = secs3;

        tc.tic();
        MergeSort(vec4,0,vec4.size() - 1);
        double secs4 = tc.toc();
        merge_time[n-1] = secs4;

        tc.tic();
        QuickSort(vec5,0,vec5.size() - 1);
        double secs5 = tc.toc();
        quick_time[n-1] = secs5;
    }  
    cout << "Tempi di esecuzione per BubbleSort: ";
    for (int i=0; i<bubble_time.size(); i++) {
        cout << bubble_time[i] << ",";
    }
    cout << endl;
    cout << "Tempi di esecuzione per SelectionSort: ";
    for (int i=0; i<selection_time.size(); i++) {
        cout << selection_time[i] << ",";
    }
    cout << endl;
    cout << "Tempi di esecuzione per InsertionSort: ";
    for (int i=0; i<insertion_time.size(); i++) {
        cout << insertion_time[i] << ", ";
    }
    cout << endl;
    cout << "Tempi di esecuzione per std::sort: ";
    for (int i=0; i<sort_time.size(); i++) {
        cout << sort_time[i] << ",";
    }
    cout << endl;
    cout << "Tempi di esecuzione per MergeSort: ";
    for (int i=0; i<merge_time.size(); i++) {
        cout << merge_time[i] << ", ";
    }
    cout << endl;
    cout << "Tempi di esecuzione per QuickSort: ";
    for (int i=0; i<quick_time.size(); i++) {
        cout << quick_time[i] << ", ";
    }
     cout << endl;

}