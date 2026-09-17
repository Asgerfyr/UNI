#include <iostream>



int add(int a, int b) {
    return a + b;
}


// Write this function:
int apply(int (*op)(int, int), int x, int y){
    return op(x, y);
}

int main() {


    std::cout << apply(add, 10, 3) << std::endl;

    std:std::cout << "hello" << std::endl;
    return 0;
}




