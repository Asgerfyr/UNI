#pragma once

#include <string>
#include <ostream>

struct log_entry {
    std::string time;
    std::string type;
    std::string application;
    std::string message;
};

std::ostream &operator<<(std::ostream &, const log_entry &);

bool operator==(const log_entry &, const std::string &);

bool operator==(const std::string &, const log_entry &);

bool operator==(const log_entry &, const log_entry &);