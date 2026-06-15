#pragma once
#include <sstream>// denne skal v�re der til implementering af toString
//Opgave 2 a)

#include<stdexcept>
#include <string>
#include <vector>

template<typename C>
class PolynomialTemplate
{
public:
	PolynomialTemplate(const std::vector<C>& coefficients);
	C operator()(C value) const;
	PolynomialTemplate<C> operator +(const PolynomialTemplate<C>&) const;
	size_t order() const;
	size_t size() const;
	std::string toString() const;
private:
	
	std::vector<C> coefficients_;
};

template<typename C>
PolynomialTemplate<C>::PolynomialTemplate(const std::vector<C>& coefficients)
	: coefficients_(coefficients.empty() ? std::vector<C>{0} : coefficients)
{
}

template<typename C>
C PolynomialTemplate<C>::operator()(const C value) const
{
	C res = 0;
	C power(1);
	for (const auto& coefficient : coefficients_)
	{
		res = res + coefficient * power;
		power = power * value;
	}
	return res;
}

template<typename C>
PolynomialTemplate<C> PolynomialTemplate<C>::operator+(const PolynomialTemplate<C>& other) const
{
	const size_t maxSize = std::max(other.coefficients_.size(), coefficients_.size());
	std::vector<C> newCoefficients;
	for (size_t i = 0; i < maxSize; ++i)
	{
		const C value1 = (i < other.size()) ? other.coefficients_[i] : 0;
		const C value2 = (i < size()) ? coefficients_[i] : 0;
		newCoefficients.push_back(value1 + value2);
	}
	return {newCoefficients};
}

template<typename C>
size_t PolynomialTemplate<C>::order() const
{
	return coefficients_.size() - 1;
}

template<typename C>
size_t PolynomialTemplate<C>::size() const
{
	return coefficients_.size();
}

template<typename C>
std::string PolynomialTemplate<C>::toString() const
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
