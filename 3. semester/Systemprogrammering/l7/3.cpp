#include <algorithm>
#include <iostream>
#include <functional>
#include <iterator>


int main() {
    
    int numbers[] = {1,2,3,4,5}; 

    // square each element in the array
    std::transform(std::begin(numbers), std::end(numbers), std::begin(numbers), [](int x){ return x * x; });
    
    // print each element in the array
    // a loop i requered so this is not allowed   std::for_each(std::begin(numbers), std::end(numbers), [](int x){ std::cout << x << std::endl; });
    for(auto x : numbers) std::cout << x << std::endl;
    
    return 0;
}




