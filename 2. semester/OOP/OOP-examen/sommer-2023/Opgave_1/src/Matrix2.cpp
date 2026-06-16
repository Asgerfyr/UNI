#include "Matrix2.h"

Matrix2::Matrix2(const double k11,
                 const double k12,
                 const double k21,
                 const double k22):
                 k11(k11),
                 k12(k12),
                 k21(k21),
                 k22(k22){}

std::ostream &operator<<(std::ostream &os, const Matrix2 &m){
    os << "[[" << m.k11 << "," << m.k12 << "],[" << m.k21 << "," << m.k22 << "]]";
    return os;
}

Matrix2 operator*(const Matrix2 &left, const Matrix2 &right){
    double k11_new = left.k11*right.k11+left.k12*right.k21;
    double k12_new = left.k11*right.k12+left.k12*right.k22;
    double k21_new = left.k21*right.k11+left.k22*right.k21;
    double k22_new = left.k21*right.k12+left.k22*right.k22;
    return {k11_new,k12_new,k21_new,k22_new};
}