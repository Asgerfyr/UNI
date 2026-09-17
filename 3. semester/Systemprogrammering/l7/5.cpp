#include <algorithm>
#include <iostream>
#include <functional>
#include <iterator>
#include <vector>



std::vector<int> transform(const std::vector<int>& input, std::function<int(int)> f){
    std::vector<int> output;
    for(int x : input) output.push_back(f(x));
    return output;
}


int main() {
    
    std::vector<int> numbers = {1,2,3,4,5}; 

    std::vector<int> new_numbers = transform(numbers, [](int x){ return x % 2; });

    for(auto x : new_numbers) std::cout << x << std::endl;

    
    return 0;
}




