#include "matrix_2.h"
#include <sstream>

matrix_2::matrix_2(const unsigned int rows, const unsigned int cols) : 
    rows_(rows), 
    cols_(cols){
    data_ = new double[rows*cols];
}

matrix_2::~matrix_2(){
    delete[] data_;
}

void matrix_2::set(const unsigned int row, const unsigned int col, const double value) {
    data_[(row - 1) * cols_ + (col - 1)] = value;
}

double matrix_2::get(const unsigned int row, const unsigned int col) const {
    return data_[(row - 1) * cols_ + (col - 1)];
}

std::string matrix_2::to_string() const {
    std::stringstream ss;
    ss << "[" << std::endl;

    for (size_t i = 1; i < rows_ + 1; i++) {
        ss << "[";
        for (size_t j = 1; j < cols_ + 1; j++) {
            ss << get(i, j) << " ";
        }
        ss << "]" << std::endl;
    }
    ss << "]";
    return ss.str();
}
