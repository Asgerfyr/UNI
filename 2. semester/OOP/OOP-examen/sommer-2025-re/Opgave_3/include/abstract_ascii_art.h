#pragma once
#include "ascii_art.h"

class abstract_ascii_art : public ascii_art{
public:
    void render() const override;
};