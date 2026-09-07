#include <iostream>
#include "test_4.h"
#include "email.h"
#include "sms.h"
#include "dispatcher.h"

void test_send_email() {
    std::cout << '\n';
    
    email e1{std::string("<this is the message>"),
             std::string("<this is the receiver>"),
             std::string("<This is the sender>") };
    
    std::cout << "sending mail with message:" << '\n';
    std::cout << "<this is the message>" << '\n';
    std::cout << "with receiver:" << '\n';
    std::cout << "<this is the receiver>" << '\n';
    std::cout << "with sender:" << '\n';
    std::cout << "<this is the sender>" << "\n\n";

    std::cout << e1.send() << '\n';

}

void test_send_sms() {
    std::cout << '\n';
    
    sms sms1{std::string("<this is the message>"),
        std::string("<this is the receiver number>"),
        std::string("<This is the sender number>") };
        
        std::cout << "sending mail with message:" << '\n';
        std::cout << "<this is the message>" << '\n';
        std::cout << "with receiver:" << '\n';
        std::cout << "<this is the receiver number>" << '\n';
        std::cout << "with sender:" << '\n';
        std::cout << "<this is the sender number>" << "\n\n";
        
        std::cout << sms1.send() << '\n';
        
    }
    
    void test_dispatcher() {
        std::cout << '\n';
        std::cout << "Used same objects as in the last 2 tests:" << "\n\n";
        
        dispatcher d;

    email e1{std::string("<this is the message>"),
             std::string("<this is the receiver>"),
             std::string("<This is the sender>") };

    sms sms1{std::string("<this is the message>"),
             std::string("<this is the receiver number>"),
             std::string("<This is the sender number>") };

    d.add_message(&e1);
    d.add_message(&sms1);

    d.send_all();

}
