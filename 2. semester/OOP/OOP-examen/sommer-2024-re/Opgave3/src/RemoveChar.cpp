#include "RemoveChar.h"

// Opgave 3 g)

void RemoveChar::process(std::string &text){
    for (auto it = text.begin(); it != text.end(); ++it) {
        if((*it) != c) continue;
        it = text.erase(it);
    }
}