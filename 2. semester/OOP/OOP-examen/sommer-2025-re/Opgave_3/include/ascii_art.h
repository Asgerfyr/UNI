#pragma once

class ascii_art {
public:
    virtual void render_line(unsigned int i)const = 0;
    virtual void render()const = 0;
    virtual unsigned int height()const = 0;
};