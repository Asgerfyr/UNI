#pragma once
#include <ostream>

//Opgave 1 a )
class Fraction{
public:

    Fraction(const int nominator, const int denominator);
    int getNominator() const;
    int getDenominator() const;
    bool operator==(const Fraction fraction);
    friend std::ostream & operator<<(std::ostream &os, Fraction fraction); 
    friend Fraction operator+(Fraction left, Fraction right); 
    
    
    private:
    int nominator_;
    int denominator_;
    
};

//Opgave 1 d )
std::ostream & operator<<(std::ostream &os, Fraction fraction); 
Fraction operator+(Fraction left, Fraction right); 



//Opgave 1 f)


