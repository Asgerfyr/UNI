#include <algorithm>
#include <iostream>
#include <functional>
#include <iterator>



int add(int a, int b) {
    return a + b;
}

// Write this function:
int apply(int (*op)(int, int), int x, int y){
    return op(x, y);
}

//this can sadly not be used for the forEach function because it expects a function pointer, not a std::function
std::function<int(int)> make_adder(int add_num){
    return [add_num](int b) {
        return add(add_num, b);
    };
}


void forEach(int* arr, int size, int (*func)(int)){
    int* begin = arr;
    int* end = arr + size;
    std::transform(begin, end, begin, func);
}

void forEach_non_mutable(int* arr, int size, int (*func)(int)){
    int* begin = arr;
    int* end = arr + size;
    std::for_each(begin, end, func);
}



int main() {
    
    int numbers[] = {1,2,3,4,5,6,7,8,9,10}; 

    forEach(numbers,std::size(numbers),[](int x){return x+x;});
    
    forEach_non_mutable(numbers,std::size(numbers),[](int x){printf("%d\n", x); return x;});

    
    return 0;
}




