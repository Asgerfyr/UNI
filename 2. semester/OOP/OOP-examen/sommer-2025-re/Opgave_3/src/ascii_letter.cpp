#include "ascii_letter.h"
#include <iostream>

ascii_letter::ascii_letter(const std::vector<std::string> &init):data_(init) {
}

unsigned int ascii_letter::height() const{
    return data_.size();
}

void ascii_letter::render_line(unsigned int line) const{
    std::cout << data_[line];
}

