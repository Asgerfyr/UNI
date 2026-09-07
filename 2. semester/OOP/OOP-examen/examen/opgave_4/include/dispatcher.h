#pragma once
#include "message.h"

class dispatcher {
public:
    void add_message(message *mes);
    void send_all();
    
private:
    std::vector<message *> messages_;
};
