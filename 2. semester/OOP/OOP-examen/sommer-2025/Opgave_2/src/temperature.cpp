#include "temperature.h"

temperature::temperature(double value) : value_(value) {}

double temperature::to_fahrenheit() const {
    return value_ * 5 / 9 + 32;
}

double temperature::to_celsius() const {
    return value_;
}

temperature temperature::operator+(const temperature &right) const {
    return temperature{right.value_ + value_};
}

bool temperature::operator<(const temperature &right) const {
    return value_ < right.value_;
}

bool temperature::operator>(const temperature &right) const {
    return value_ > right.value_;
}

temperature temperature::operator*(double scaling_factor) const {
    return temperature{scaling_factor * value_};
}

temperature temperature::operator/(double factor) const {
    return temperature{value_ / factor};
}

std::ostream &operator<<(std::ostream &os, const temperature &t) {
    os << t.to_celsius() << " Degrees Celsius";
    return os;
}