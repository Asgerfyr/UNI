#pragma once
#include <string>
#include "message.h"

class email : public message{
public:
    email(const std::string &, const std::string &, const std::string &);
    std::string send() const override;
private:
    std::string message_;
    std::string receiver_email_;
    std::string sender_email_;
};
