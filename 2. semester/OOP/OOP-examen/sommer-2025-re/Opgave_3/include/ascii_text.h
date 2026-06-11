#pragma once
#include "abstract_ascii_art.h"
#include "ascii_art.h"
#include <vector>

class ascii_text : public abstract_ascii_art{
public:
    void add(ascii_art *);
    unsigned int height() const override;
    void render_line(unsigned int line) const override;

private:
    std::vector<ascii_art *> arts_;
};