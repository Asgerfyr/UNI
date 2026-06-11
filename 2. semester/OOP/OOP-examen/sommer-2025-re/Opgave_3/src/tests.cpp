#include <cassert>// if you want to use assertions
#include "tests.h"
#include "letter_factory.h"
#include "ascii_letter.h"
#include "ascii_text.h"

void test_abstract_ascii_art_render() {
    abstract_ascii_art_test art_obj;
    art_obj.render();
}

void test_ascii_letter_e() {
    ascii_letter letter{create_e()};
    letter.render();

}

void test_ascii_text_exam() {
    ascii_text text;
    ascii_letter letter_e{create_e()};
    ascii_letter letter_x{create_x()};
    ascii_letter letter_a{create_a()};
    ascii_letter letter_m{create_m()};
    ascii_letter letter_space{create_space()};
    
    text.add(&letter_e);
    text.add(&letter_space);
    text.add(&letter_x);
    text.add(&letter_space);
    text.add(&letter_a);
    text.add(&letter_space);
    text.add(&letter_m);
    
    text.render();
    
    ascii_letter letter_error{create_wrong_height()};
    text.add(&letter_error);
}