#include <cmath>
#include "box.h"

//initialization of static member
const double box::delta = 0.001;

// ctor implementation
box::box(double length, double width, double height) : length_(length), width_(width), height_(height) {}

//implementation of volume
double box::volume() const {
    return length_ * width_ * height_;
}

bool box::operator==(const box &right) const{
    return std::abs(this->volume()-right.volume()) < delta; 
}


bool operator<(const box &b_1, const box &b_2){
    return b_1.volume() < (b_2.volume() - box::delta);
}