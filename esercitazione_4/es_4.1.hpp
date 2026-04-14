#include <vector>
#include <algorithm>
#include <iostream>
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
void print_vector(const vector<T>& vec) {
    for (size_t i=0; i<vec.size(); i++) {
        cout << vec[i]<< " ";
    }
}

//BubbleSort 
template<typename T>
void BubbleSort(vector<T>& vec) {
    if (vec.empty()) return;
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
    if (vec.empty()) return;
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
    if (vec.empty()) return;
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