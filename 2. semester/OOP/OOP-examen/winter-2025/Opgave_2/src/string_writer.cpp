#include "string_writer.h"

std::string as_string(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
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
