#pragma once
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

template<typename T>
class Matrix {
public:
    Matrix(const int cols_, const int rows_);

    void set(const int col_, const int row_, T item_);

    T& get(const int col_, const int row_);

    std::string to_string()const;

    int get_n_cols()const;
    int get_n_rows()const;

    std::vector<T>& get_matrix_vec();
    

private:
    std::vector<T> _values;
    int _rows;
    int _cols;
};


template<typename T>
Matrix<T>::Matrix(const int cols_, const int rows_):_values(cols_*rows_){
    this->_rows = rows_;
    this->_cols = cols_;
}

template<typename T>
void Matrix<T>::set(const int col_, const int row_, T item_){
    if(row_ < 0 || row_ >= _rows) throw std::invalid_argument("The desired row is not in range");
    if(col_ < 0 || col_ >= _cols) throw std::invalid_argument("The desired col is not in range");
    _values[_cols*row_+col_] = item_;
}

template<typename T>
T& Matrix<T>::get(const int col_, const int row_){
    if(row_ < 0 || row_ >= _rows) throw std::invalid_argument("The desired row is not in range");
    if(col_ < 0 || col_ >= _cols) throw std::invalid_argument("The desired col is not in range");
    return _values[_cols*row_+col_];
}

template<typename T>
int Matrix<T>::get_n_cols()const {
    return _cols;
}

template<typename T>
int Matrix<T>::get_n_rows()const {
    return _rows;
}


template<typename T>
std::string Matrix<T>::to_string()const {
    
    std::stringstream ss;
    
    for (auto it = _values.begin(); it != _values.end(); ++it) {
        if(std::distance(_values.begin(),it)%_cols==0  && std::distance(_values.begin(),it) != 0){
            ss << std::endl;
        }
        ss << it->to_string();
    }
    
    return ss.str();
}


template<typename T>
std::vector<T>& Matrix<T>::get_matrix_vec(){
    return _values;
}