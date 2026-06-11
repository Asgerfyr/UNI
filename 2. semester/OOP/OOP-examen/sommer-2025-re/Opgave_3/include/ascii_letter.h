#pragma once
#include "abstract_ascii_art.h"
#include <string>
#include <vector>

class ascii_letter : public abstract_ascii_art{
public:
    ascii_letter(const std::vector<std::string> &init);
    unsigned int height() const override;
    void render_line(unsigned int line) const override;

private:
    std::vector<std::string> data_;
};