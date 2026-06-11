#pragma once

#include <iostream>
#include "abstract_ascii_art.h"

//de-comment when implementing

class abstract_ascii_art_test : public abstract_ascii_art {
public:
    void render_line(unsigned int) const override {
        std::cout << "test";
    }

    unsigned int height() const override {
        return 3;
    }
};

void test_abstract_ascii_art_render();

void test_ascii_letter_e();

void test_ascii_text_exam();


