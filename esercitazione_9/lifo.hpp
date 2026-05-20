#include <stack>
#include <iostream>

using namespace std;

template <typename T>
class lifo {
    stack<T> stack1;

public:

lifo() = default;

void put(T element) {
    stack1.push(element);
}

bool empty() {
    return stack1.empty();
}

T get(){
    if(stack1.empty()) {
        cout << "Il contenitore è vuoto" << endl;
        return T();
    }else{
        T elemento = stack1.top();
        stack1.pop();
        return elemento;
    }   
}

};