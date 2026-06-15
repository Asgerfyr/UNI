#include "ToUpperCase.h"
#include "Util.h"
// Opgave 3 c)

void ToUpperCase::process(std::string &text){
    for (auto it = text.begin(); it != text.end(); ++it) {
        (*it) = toUpper((*it));
    }
}