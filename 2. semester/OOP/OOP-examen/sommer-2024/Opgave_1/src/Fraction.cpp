
//Opgave 1 b)
#include "Fraction.h"
#include <stdexcept>

Fraction::Fraction(const int nominator, const int denominator): nominator_(nominator){
    if(denominator == 0) throw std::invalid_argument("denominator can't be 0");
    denominator_ = denominator;

}


int Fraction::getNominator() const{
    return nominator_;
}

int Fraction::getDenominator() const{
    return denominator_;
}

bool Fraction::operator==(Fraction fraction){
    return this->nominator_*fraction.denominator_ == fraction.nominator_*this->denominator_;
}

//Opgave 1 d)
std::ostream & operator<<(std::ostream &os, Fraction fraction) {
    os << fraction.nominator_ << "/" << fraction.denominator_;
    return os;
}


//Opgave 1 f)
Fraction operator+(Fraction left, Fraction right){
    const int nomi = left.nominator_*right.denominator_ + right.nominator_*left.denominator_;
    const int denomi = right.denominator_*left.denominator_;
    
    return{nomi,denomi};
}