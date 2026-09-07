#include "matrix_1.h"
#include <sstream>
#include <stdexcept>

matrix_1::matrix_1(const unsigned int rows, const unsigned int cols) : rows_(rows), cols_(cols), data_(rows * cols) {
}

void matrix_1::set(const unsigned int row, const unsigned int col, const double value) {
    if(row < 1 || row > rows_) throw std::invalid_argument("argument row in set of matrix_1.cpp is out of range. value: " + std::to_string(row));   
    if(col < 1 || col > cols_) throw std::invalid_argument("argument col in set of matrix_1.cpp is out of range. value: " + std::to_string(col));   
    data_[(row - 1) * cols_ + (col - 1)] = value;
}


double matrix_1::get(const unsigned int row, const unsigned int col) const {
    if(row < 1 || row > rows_) throw std::invalid_argument("argument row in get of matrix_1.cpp is out of range. value: " + std::to_string(row));   
    if(col < 1 || col > cols_) throw std::invalid_argument("argument col in get of matrix_1.cpp is out of range. value: " + std::to_string(col));   
    return data_[(row - 1) * cols_ + (col - 1)];
}

std::string matrix_1::to_string() const {
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


matrix_1 matrix_1::operator+(const matrix_1 other) const{
    if(this->rows_ != other.rows_ || this->cols_ != other.cols_) throw std::invalid_argument("matrix not same dimensions");
    matrix_1 matrix_new{rows_,cols_};
    
    for (unsigned int i = 1; i < rows_+1; i++)
    {
        for (unsigned int j = 1; j < cols_+1; j++)
        {
            double val_new = this->get(i,j)+other.get(i,j);
            matrix_new.set(i,j,val_new);
        }
    }

    return matrix_new;
}

std::ostream &operator<<(std::ostream &os, const matrix_1 &matrix){
    os << matrix.to_string();
    return os;
}



