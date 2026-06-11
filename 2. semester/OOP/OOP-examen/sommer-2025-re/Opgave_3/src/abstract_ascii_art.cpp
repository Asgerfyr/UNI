#include "abstract_ascii_art.h"
#include <iostream>

void abstract_ascii_art::render() const{
    for(unsigned int i = 0; i < height(); i++){
        render_line(i);
        std::cout << '\n';
    }
}