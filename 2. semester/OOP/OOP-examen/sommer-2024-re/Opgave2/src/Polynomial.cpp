#include "Polynomial.h"

#include <sstream>
#include<stdexcept>

Polynomial::Polynomial(const std::vector<double>& coefficients)
	: coefficients_(coefficients.empty() ? std::vector<double>{0} : coefficients)
{
}

double Polynomial::operator()(const double value) const
{
	double res = 0;
	double power(1);
	for (const auto& coefficient : coefficients_)
	{
		res = res + coefficient * power;
		power = power * value;
	}
	return res;
}

Polynomial Polynomial::operator+(const Polynomial& other) const
{
	const size_t maxSize = std::max(other.coefficients_.size(), coefficients_.size());
	std::vector<double> newCoefficients;
	for (size_t i = 0; i < maxSize; ++i)
	{
		const double value1 = (i < other.size()) ? other.coefficients_[i] : 0;
		const double value2 = (i < size()) ? coefficients_[i] : 0;
		newCoefficients.push_back(value1 + value2);
	}
	return {newCoefficients};
}

size_t Polynomial::order() const
{
	return coefficients_.size() - 1;
}

size_t Polynomial::size() const
{
	return coefficients_.size();
}

std::string Polynomial::toString() const
{
	std::ostringstream res;

	for (size_t i = 0; i < coefficients_.size(); ++i)
	{
		if (i > 0)
		{
			res << " + ";
		}
		res << coefficients_[i] << "*x^" << i;
	}
	return res.str();
}
