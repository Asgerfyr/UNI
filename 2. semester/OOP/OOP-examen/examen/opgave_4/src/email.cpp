#include "email.h"
#include <sstream>

email::email(const std::string &message, const std::string &receiver, const std::string &sender)
    : message_(message), receiver_email_(receiver), sender_email_(sender) {
}

std::string email::send() const{
    std::stringstream res_str;
    res_str << "Sernding email ";
    res_str << message_;
    res_str << " from ";
    res_str << sender_email_;
    res_str << " to ";
    res_str << receiver_email_;

    return res_str.str();
}