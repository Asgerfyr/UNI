#include <algorithm>
#include <iostream>
#include <functional>
#include <iterator>
#include <vector>



std::function<int(int)> compose(std::function<int(int)> f1, std::function<int(int)> f2){
    return [f1,f2](int x){return f1(f2(x));};
}


int main() {
    
    std::vector<int> numbers = {1,2,3,4,5}; 
    
    auto add2 = [](int x){ return x + 2;};
    auto multiply3 = [](int x){ return x * 3;};
    
    auto add2_then_multiply3 = [add2, multiply3](int x){ return multiply3(add2(x));};
    
    auto composed_function = compose(add2, multiply3);
    
    std::transform(std::begin(numbers), std::end(numbers), std::begin(numbers), composed_function);
    
    for(auto x : numbers) std::cout << x << std::endl;
    

    std::vector<int> numbers_2 = {1,2,3,4,5}; 
    
    std::transform(std::begin(numbers_2), std::end(numbers_2), std::begin(numbers_2), add2_then_multiply3);

    for(auto x : numbers_2) std::cout << x << std::endl;

    
    return 0;
}




