#include <algorithm>
#include <iostream>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>



int main() {
    
    std::vector<int> numbers = {1,2,3,4,5}; 
    
    std::transform(std::begin(numbers), std::end(numbers), std::begin(numbers),[](int x){return x*2;});

    int res = std::accumulate(std::begin(numbers), std::end(numbers), 0);

    std::cout << res << std::endl;
    
    return 0;
}




