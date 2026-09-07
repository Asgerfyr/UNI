#pragma once
#include "message.h"


class sms : public message{
public:
    sms(const std::string &, const std::string &, const std::string &);
    std::string send() const override;
private:
    std::string message_;
    std::string receiver_mobile_;
    std::string sender_mobile_;
};
