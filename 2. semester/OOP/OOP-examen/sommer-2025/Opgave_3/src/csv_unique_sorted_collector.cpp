#include "csv_unique_sorted_collector.h"

csv_unique_sorted_collector::csv_unique_sorted_collector(double upper_limit) : upper_limit_(upper_limit) {}

bool csv_unique_sorted_collector::filter(double value) const{
    return value <=upper_limit_;
} 

std::string csv_unique_sorted_collector::format(double value) const {
    return std::to_string(value)+",";
} 
