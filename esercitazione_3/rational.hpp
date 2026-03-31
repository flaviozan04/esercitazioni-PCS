#include <concepts>
#include <numeric>
#include <iostream>
template<typename I>
requires std::integral<I>
class rational {
 
	I num_;
	I den_;
	


	
	I gcd(I a, I b) {
		while (b != 0) {
			I r = a % b;
			a = b;
			b = r;
    }
	return a;
	}
 
	//normalizzare
	void normalize() {
		I g = gcd(num_, den_);
		num_ /= g;
		den_ /= g;
		
    if (den_ < 0) {
        den_ = -den_;
        num_ = -num_;
    }
	}
		
	
public:
	rational()
		: num_(0) , den_(1)
	{}
 
	 rational(const I& n, const I& d)
		: num_(n), den_(d)
	{
		if (den_==0) {
			if (num_==0){
				//Nan
			}
			else {
				if (num_>0){
					//+Inf
			}
				else{
					//-Inf
			}
		}
		}
		normalize();
	}
	
	
	
	
	
	
	I num() const { return num_; }
	I den() const { return den_; }

	bool nan() const { return den_ == 0 && num_ == 0; }
    bool inf() const { return den_ == 0 && num_ == 1; }
    bool neg_inf() const { return den_ == 0 && num_ == -1;}

	
	// +=
	rational& operator+=(const rational& other) {
        if ((this->inf() && other.inf()) || (this->neg_inf() && other.neg_inf())) { // Inf +Inf, -Inf + -Inf 
            num_ = num_ + other.num_;
            if (num_ > 0) num_ = 1; // Inf 
            else if (num_ < 0) num_ = -1; // -Inf
            else num_ = 0; // NaN
        } else if ((this->inf() && other.neg_inf()) || (this->neg_inf() && other.inf())){ // Inf + -Inf, -Inf + Inf
            num_ = 0; // NaN
        } else if (this->nan() || other.nan()){  // Se uno dei due è NaN, il risultato è NaN
            num_ = 0; den_ = 0; // Nan 
        } else if ((this->inf() || this->neg_inf())&&(other.num_ != 0 && other.den_ != 0)){ // Inf + numero finito, -Inf + numero finito
            num_ = num_; // Inf o -Inf
        } else if ((other.inf() || other.neg_inf()) && (num_ != 0 && den_ != 0)){ // numero finito + Inf, numero finito + -Inf
            num_ = other.num_; // Inf o -Inf
            
        } else {
            num_ = num_ * other.den_ + other.num_ * den_;
            den_ = den_ * other.den_;
            normalize();
        }
        return *this; 
    }

	
	
	//+
	rational operator+(const rational& other) const {
    rational ret = *this;
    ret += other;
    return ret;
	}
	
	//-=
	 rational& operator-=(const rational& other) {
        rational neg_other(-other.num(), other.den());
        return *this += neg_other;
    }
	
	//-
	rational operator-(const rational& other) const {
    rational ret = *this;
    ret -= other;
    return ret;
	}
	
	
	//*=
	 rational& operator*=(const rational& other) {
        if (this->nan() || other.nan()) { // Se uno dei due è NaN, il risultato è NaN
            num_ = 0; den_ = 0; // Nan 
        } else if (this->neg_inf() && other.neg_inf()){ // -Inf * -Inf
            num_ = 1; // Inf
        } else if ((this->inf() || other.inf()) && (num_ != -1 && other.num_ != -1) && (num_<0 || other.num_<0)) { // Inf*Inf, Inf*numero finito negativo , numero finito negativo*Inf
            num_ = -1; // -Inf
        } else if ((this->inf() || other.inf()) && (num_ != -1 && other.num_ != -1) && (num_>0 || other.num_>0)) { // Inf*Inf, Inf*numero finito positivo , numero finito positivo*Inf
            num_ = 1; // Inf
        } else if ((this->neg_inf() || other.neg_inf()) && (num_ != -1 && other.num_ != -1) && (num_>0 || other.num_>0)) { // -Inf*Inf, -Inf*numero finito positivo, numero finito positivo*-Inf{
            num_ = -1; // -Inf
        } else if ((this->neg_inf() || other.neg_inf()) && (num_ != -1 && other.num_ != -1) && (num_<0 || other.num_<0)) { // -Inf*Inf, -Inf*numero finito negativo, numero finito negativo*-Inf{
            num_ = 1; // -Inf
            
        } else {
            num_ *= other.num_;
            den_ *= other.den_;
            normalize();
        }
        return *this;
    }
	
	//*
	rational operator*(const rational& other) const {
    rational ret = *this;
    ret *= other;
    return ret;
	}
	
	// /=
	rational& operator/=(const rational& other) {
        if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) { //Se uno dei due è NaN, il risultato è NaN
            num_ = 0; den_ = 0; // Nan 
        } else if ((this->inf() && other.inf()) || (this->neg_inf() && other.neg_inf()) || (this->inf() && other.neg_inf()) || (this->neg_inf() && other.inf())) { // Inf/Inf, -Inf/-Inf, Inf/-Inf, -Inf/Inf
            num_ = 0; // NaN}
        } else if (other.den_ == 0) {
            if (other.num_ > 0) {
                num_ = 1; // Inf
            } else if (other.num_ < 0) {
                num_ = -1; // -Inf
            } else {
                num_ = 0; // NaN
            }
        } else if (den_ == 0) {
            if (num_ > 0) {
                num_ = 1; // Inf
            } else if (num_ < 0) {
                num_ = -1; // -Inf
            } else {
                num_ = 0; // NaN
            }
        } else {
            num_ *= other.den_;
            den_ *= other.num_;
            normalize();
        }
        return *this;
    }
	
	// /
	rational operator/(const rational& other) const {
    rational ret = *this;
    ret /= other;
    return ret;
	}
	
	
 };

// <<
template<typename I>
requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
	if (r.den() == 0) {
		if (r.num() == 0) os << "NaN";
		else if (r.num() == -1) os << "-Inf";
		else os << "+Inf";
	} else {
			os << r.num() << "/" << r.den();
		}
	return os;
};