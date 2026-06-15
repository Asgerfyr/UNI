#pragma once
#include <string>
#include <vector>

class Polynomial
{
public:
	Polynomial(const std::vector<double>& coefficients);
	double operator()(double value) const;
	Polynomial operator +(const Polynomial&) const;
	size_t order() const;
	size_t size() const;
	std::string toString() const;
private:
	
	std::vector<double> coefficients_;
};

