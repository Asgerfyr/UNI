#include "dispatcher.h"
#include <iostream>

void dispatcher::add_message(message *mes){
    messages_.emplace_back(mes);
    return;
}


void dispatcher::send_all(){
    //use first in first out
    for (auto it = messages_.begin(); it != messages_.end(); ++it) {
        std::cout << (*it)->send() << '\n';
        std::cout << "\n\n";
    }
    messages_.clear(); 
    return;
}