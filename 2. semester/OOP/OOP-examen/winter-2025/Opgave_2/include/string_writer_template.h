#pragma  once
#include <sstream>


template<typename T>

std::string as_string(T begin, T end){
    bool first = true;
    std::ostringstream os;
    for (auto it = begin; it != end; ++it) {
        if (!first) {
            os << ", ";
        }
        os << *it;
        first = false;
    }
    return os.str();
}
