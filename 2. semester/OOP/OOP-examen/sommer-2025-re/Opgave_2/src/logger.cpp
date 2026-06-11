#include <iostream>
#include "logger.h"

void logger::print() const {
    for (const auto &log: log_entries_) {
        std::cout << log.first << ":" << log.second << "\n";
    }
}

size_t logger::count() const {
    return log_entries_.size();
}

void logger::log(const std::string &time, const std::string &log) {
    log_entries_.emplace_back(time, log);
}

std::vector<std::pair<std::string, std::string>> logger::contains(const std::string &message) {
    std::vector<std::pair<std::string, std::string>> result;
    for (const auto &l: log_entries_) {
        if (l.second == message) {
            result.push_back(l);
        }
    }
    return result;
}