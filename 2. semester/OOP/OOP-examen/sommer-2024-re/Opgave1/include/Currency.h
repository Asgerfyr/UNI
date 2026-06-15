#pragma once
#include <string>

class Currency
{
	
public:
	Currency(const std::string& symbol,double factor);
	double toStandardCurrency(double amount) const;
	double fromStandardCurrency(double amount) const;
	std::string getSymbol() const;
private:
	std::string symbol_;
	double factor_;
};

