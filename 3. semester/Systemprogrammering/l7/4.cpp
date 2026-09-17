#include <algorithm>
#include <iostream>
#include <functional>
#include <iterator>


int main() {
    
    int numbers[] = {1,2,3,4,5}; 

    auto multiply = [&numbers](int mult){
        std::transform(std::begin(numbers), std::end(numbers), std::begin(numbers), [mult](int x){ return x * mult; });
    };

    multiply(2);

    for(auto x : numbers) std::cout << x << std::endl;


    multiply(3);

    for(auto x : numbers) std::cout << x << std::endl;

    
    return 0;
}




