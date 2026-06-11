#pragma once

#include <iostream>

class temperature {
public:
    explicit temperature(double value=0);

    [[nodiscard]] double to_fahrenheit() const;

    [[nodiscard]] double to_celsius() const;

    bool operator<(const temperature &right) const;

    bool operator>(const temperature &right) const;

    temperature operator+(const temperature &right) const;

    temperature operator*(double scaling_factor) const;

    temperature operator/(double scaling_factor) const;

private:
    double value_;//celsius
};

std::ostream &operator<<(std::ostream &os, const temperature &);
