#include <iostream>
#include <concepts>
#include <algorithm>

using namespace std;

template<typename T> 
class unidirected_edge { 

        T from_;
        T to_;
        
public:

    T from() const { return from_; }
    T to() const { return to_; }

    unidirected_edge() : from_(0), to_(0) {}

    unidirected_edge(T node1, T node2) : from_(min(node1, node2)), to_(max(node1, node2)) {
    }

    bool operator==(const unidirected_edge& other) const {
        if (this->from() == other.from() && this->to() == other.to()) {
            return true;
        }else{ 
            return false;
        }
    }

    bool operator<(const unidirected_edge& other) const {
        if (this->from() != other.from()) {
            if(this->from() < other.from()) {
                return true;
            } else {
                return false;
            }
        }
        else if(this->to() < other.to()) {
            return true;
        } else {
            return false;
        }
    }
};
template <typename T>
ostream& operator<<(ostream& os, const unidirected_edge<T>& e) {
    os << "(" << e.from() << ", " << e.to() << ")";
    return os;
}