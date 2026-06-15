#pragma once
#include "StringProcessor.h"

// Opgave 3 f)
class RemoveChar : public StringProcessor
{
public:
    RemoveChar(char c):StringProcessor(),c(c){};
    
    void process(std::string &text) override;
private:
    char c;
};
