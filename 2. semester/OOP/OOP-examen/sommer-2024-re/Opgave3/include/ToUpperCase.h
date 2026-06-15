#pragma once
#include "StringProcessor.h"

// Opgave 3 b)
class ToUpperCase : public StringProcessor
{
public:
    void process(std::string &text) override;
};
