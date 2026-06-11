#include <stdexcept>
#include <iostream>
#include "ascii_art.h"
#include "ascii_text.h"


void ascii_text::add(ascii_art *art) {
    if (!arts_.empty() && art->height() != arts_.back()->height()) {
        throw std::invalid_argument("added art is of wrong height");
    }
    arts_.push_back(art);

}


unsigned int ascii_text::height() const{
    return arts_[0]->height();
}

void ascii_text::render_line(unsigned int line) const{
    for (auto it = arts_.begin(); it != arts_.end(); ++it) {
        (*it)->render_line(line);
    }
}
