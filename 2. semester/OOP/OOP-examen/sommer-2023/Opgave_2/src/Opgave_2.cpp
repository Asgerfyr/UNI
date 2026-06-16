#include "Drawing.h"
#include "Rectangle.h"
#include "Circle.h"

int main(int argc, char const *argv[])
{
    Drawing d1{9};
    d1.add(new Rectangle{Point{1,2},10,10});
    d1.add(new Circle{Point{-2,2},1});
    d1.print();
    return 0;
}
