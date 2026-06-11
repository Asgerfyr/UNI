#include "data_collector.h"
//Remove comments /* .. */ when starting implementation

void data_collector::receive(double value) {
    if (filter(value)) {
        collect(value);
    }
}

std::string data_collector::print() {
    auto data = prepare();
    std::string s;
    for (auto d: data) {
        s.append(format(d));
        s.append("\n");
    }
    return s;
}
 

