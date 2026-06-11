#include "log_entry.h"

std::ostream &operator<<(std::ostream &os, const log_entry &entry) {
    os << "Time:" << entry.time << " Type:" << entry.type << " Application:" << entry.application << " Message:"
       << entry.message;
    return os;
}

bool operator==(const log_entry &left, const std::string &right) {
    return left.message == right;
}

bool operator==(const std::string &left, const log_entry &right) {
    return right.message == left;
}

bool operator==(const log_entry &left, const log_entry &right) {
    return right.message == left.message;
}