#include <iostream>
#include "tests.h"

int main() {
    std::cout << "**********test_abstract_ascii_art_render*********************" << "\n";
    test_abstract_ascii_art_render();
    std::cout << "\n" << "*************************************************************" << "\n";

    std::cout << "**********test_ascii_letter_e*********************" << "\n";
    test_ascii_letter_e();
    std::cout << "\n" << "*************************************************************" << "\n";

    std::cout << "**********test_ascii_text_exam*********************" << "\n" << "\n";
    test_ascii_text_exam();
    std::cout << "\n" << "*************************************************************" << "\n";

    return 0;
}