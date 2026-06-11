#include <sstream>
#include "boxes.h"
#include <vector>
#include <algorithm>

void boxes::add_box(const box &b) {
    boxes_.emplace_back(b);
}

std::string boxes::to_string() const{
    std::stringstream return_str;
    return_str << "boxes:" << std::endl;
    for (auto it = boxes_.begin(); it != boxes_.end(); ++it) {
        return_str << "box " << std::distance(boxes_.begin(), it)+1 << ": " << std::endl;
        return_str << (*it).volume() << std::endl << std::endl;
    }
    return return_str.str();
}

std::string boxes::to_string_sorted() const{

    
    std::vector<box> boxes_temp;
    std::copy(boxes_.begin(), boxes_.end(), std::back_inserter(boxes_temp));
    
    #include <algorithm>
    
    std::sort(boxes_temp.begin(), boxes_temp.end());
    
    std::stringstream return_str; //this is duplicate code that can be refactored 
    return_str << "boxes:" << std::endl;
    for (auto it = boxes_temp.begin(); it != boxes_temp.end(); ++it) {
        return_str << "box " << std::distance(boxes_temp.begin(), it)+1 << ": " << std::endl;
        return_str << (*it).volume() << std::endl << std::endl;
    }
    return return_str.str();
}
