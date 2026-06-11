#include "unique_sorted_collector.h"
#include <algorithm>


void unique_sorted_collector::collect(double value) {
    data_.emplace(value);    
    return;
}

std::vector<double> unique_sorted_collector::prepare() const{
    return {data_.begin(),data_.end()};
}


