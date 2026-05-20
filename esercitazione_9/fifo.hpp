#include <queue>
#include <iostream>

using namespace std;

template <typename T>
class fifo {
    queue<T> queue1;

public:

fifo() = default;

void put(T element) {
    queue1.push(element);
    }

bool empty() {
    return queue1.empty();
}

T get(){
    if(queue1.empty()) {
        cout << "Il contenitore è vuoto" << endl;
        return T();
    }else{
       T elemento = queue1.front();
        queue1.pop();
        return elemento;
    }  
}

};