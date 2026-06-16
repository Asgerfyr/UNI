#include <ostream>


class Matrix2
{
public:
    Matrix2(const double k11 = 1,
            const double k12 = 0,
            const double k21 = 0,
            const double k22 = 1);
    friend std::ostream &operator<<(std::ostream &os, const Matrix2 &m);
    friend Matrix2 operator*(const Matrix2 &left, const Matrix2 &right);
    
private:
        double k11,k12,k21,k22;
};


std::ostream &operator<<(std::ostream &os, const Matrix2 &m);

Matrix2 operator*(const Matrix2 &left, const Matrix2 &right);
