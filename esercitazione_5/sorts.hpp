#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

//Verifica se il vettore è ordinato
template<typename T>
bool is_sorted(const vector<T>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}

//Stampa il vettore
template<typename T>
void print_vector(vector<T>& vec) {
    for (size_t i=0; i<vec.size(); i++) {
        cout << vec[i]<< " ";
    }
}

//BubbleSort 
template<typename T>
void BubbleSort(vector<T>& vec) {
    if (vec.size() <= 1) return;
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

//SelectionSort 
template<typename T>
void SelectionSort(vector<T>& vec) {
    if (vec.size() <= 1) return;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        swap(vec[i], vec[min_index]);
    }
}

//InsertionSort 
template<typename T>
void InsertionSort(vector<T>& vec) {
    if (vec.size() <= 1) return;
    for (size_t i = 1; i < vec.size(); i++) {
        T temp = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > temp) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = temp;
    }
}

//MergeSort
template<typename T>
void Merge(vector<T>& vec, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<T> L(n1+1);
    vector<T> R(n2+1);
    for(int i=0; i < n1; i++) {
        L[i] = vec[p + i];
    }
    for(int j=0; j < n2; j++) {
        R[j] = vec[q + j + 1];
    }
    
    int i = 0;
    int j = 0;
    int k = p; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void MergeSort(vector<T>& vec, int p, int r) {
    if (vec.size() <= 1) return;
    if(p < r) {
        int q = floor((p + r) / 2);
        MergeSort(vec, p, q);
        MergeSort(vec, q + 1, r);
        Merge(vec, p, q, r);
    }
}

//Quicksort
template<typename T>
int Partition(vector<T>& vec, int p, int r) {
    T x = vec[r];
    int i = p - 1;
    for (int j = p; j < r - 1; j++) {
        if (vec[j + 1] <= x) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[r]);
    return i + 1;
}

template<typename T>
void QuickSort(vector<T>& vec, int p, int r) {
    if (vec.size() <= 1) return;
    if (p < r) {
        int q = Partition(vec, p, r);
        QuickSort(vec, p, q - 1);
        QuickSort(vec, q + 1, r);
    }
}