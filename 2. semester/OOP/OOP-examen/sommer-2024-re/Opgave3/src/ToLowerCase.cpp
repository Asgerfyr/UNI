#include "ToLowerCase.h"
#include "Util.h"
// Opgave 3 e)


void ToLowerCase::process(std::string &text){
    for (auto it = text.begin(); it != text.end(); ++it) {
        (*it) = toLower((*it));
    }
}