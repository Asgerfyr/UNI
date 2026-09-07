#pragma once
#include <vector>
#include <string>
#include <ostream>

class matrix_1 {
public:
    matrix_1(unsigned int rows, unsigned int cols);

    void set(unsigned int, unsigned int, double);

    double get(unsigned int, unsigned int) const;

    matrix_1 operator+(const matrix_1 other) const;

    std::string to_string() const;

    friend std::ostream &operator<<(std::ostream &os, const matrix_1 &matrix);

private:
    unsigned int rows_;
    unsigned int cols_;
    std::vector<double> data_;
};




std::ostream &operator<<(std::ostream &os, const matrix_1 &matrix);


