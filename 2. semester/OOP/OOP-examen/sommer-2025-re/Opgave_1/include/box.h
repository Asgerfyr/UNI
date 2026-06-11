#pragma once
class box {
public:
    box(double, double, double);
    double volume() const;

    bool operator==(const box &right) const;

    static const double delta;
private:
    double length_, width_, height_;
};


bool operator<(const box &b_1, const box &b_2);