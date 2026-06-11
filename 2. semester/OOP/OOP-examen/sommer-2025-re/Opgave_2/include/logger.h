#pragma once

#include <vector>
#include <string>

class logger {

public:
    void log(const std::string &time, const std::string &log);

    void print() const;

    size_t count() const;

    std::vector<std::pair<std::string,std::string>> contains(const std::string &);

private:
    std::vector<std::pair<std::string, std::string>> log_entries_;
};