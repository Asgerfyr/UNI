#include "sms.h"
#include <sstream>
#include <string>

sms::sms(const std::string &message, const std::string &receiver, const std::string &sender)
    : message_(message), receiver_mobile_(receiver), sender_mobile_(sender) {
}

std::string sms::send() const{
    std::stringstream res_str;
    res_str << "Sernding sms ";
    res_str << message_;
    res_str << " from ";
    res_str << receiver_mobile_;
    res_str << " to ";
    res_str << sender_mobile_;

    return res_str.str();
}
