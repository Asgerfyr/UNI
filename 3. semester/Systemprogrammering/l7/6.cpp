#include <algorithm>
#include <iostream>
#include <functional>
#include <iterator>
#include <vector>



std::vector<int> filter(const std::vector<int>& input, std::function<bool(int)> pred){
    std::vector<int> output;
    std::copy_if(std::begin(input), std::end(input), std::back_inserter(output), pred);
    return output;
}


int main() {
    
    std::vector<int> numbers = {1,2,3,4,5}; 

    std::vector<int> new_numbers = filter(numbers, [](int x){ return x > 3; });

    for(auto x : new_numbers) std::cout << x << std::endl;

    
    return 0;
}




