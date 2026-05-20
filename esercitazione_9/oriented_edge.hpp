#include <iostream>
#include <concepts>

using namespace std;

template<typename T> 
class oriented_edge { 

        T from_;
        T to_;
        
public:

    T from() const { return from_; }
    T to() const { return to_; }

    oriented_edge() : from_(0), to_(0) {}

    oriented_edge(T node1, T node2) : from_(node1), to_(node2) {
    }

    bool operator==(const oriented_edge& other) const {
        if (this->from() == other.from() && this->to() == other.to()) {
            return true;
        }else{ 
            return false;
        }
    }

    bool operator<(const oriented_edge& other) const {
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
ostream& operator<<(ostream& os, const oriented_edge<T>& e) {
    os << "(" << e.from() << ", " << e.to() << ")";
    return os;
}