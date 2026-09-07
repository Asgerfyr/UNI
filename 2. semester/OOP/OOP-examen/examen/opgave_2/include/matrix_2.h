#pragma once
#include <vector>
#include <string>

class matrix_2 {
public:
    matrix_2(unsigned int rows, unsigned int cols);
    ~matrix_2();

    void set(unsigned int, unsigned int, double);

    double get(unsigned int, unsigned int) const;

    std::string to_string() const;

private:
    unsigned int rows_;
    unsigned int cols_;
    double *data_;
};
