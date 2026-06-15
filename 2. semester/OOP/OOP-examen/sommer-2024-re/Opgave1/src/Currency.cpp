#include "Currency.h"

Currency::Currency(const std::string& symbol, double factor): symbol_(symbol), factor_(factor)
{
}

double Currency::toStandardCurrency(const double amount) const
{
	return factor_ * amount;
}

double Currency::fromStandardCurrency(const double amount) const
{
	return amount / factor_;
}

std::string Currency::getSymbol() const
{
	return symbol_;
}
