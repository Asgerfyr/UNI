#pragma once
#include <iostream>
#include <string>
#include <vector>

template<typename T>
class logger_template {
    
    public:
    void log(const std::string &time, const T &log);
    
    void print() const;

    size_t count() const;

    std::vector<std::pair<std::string, T>> contains(const T &data);

private:
    std::vector<std::pair<std::string, T>> log_entries_;
};

template<typename T>
void logger_template<T>::log(const std::string &time, const T &log) {
    log_entries_.emplace_back(time, log);
}

template<typename T>
void logger_template<T>::print() const {
    for (const auto &log: log_entries_) {
        std::cout << log.first << ":" << log.second << "\n";
    }
}

template<typename T>
size_t logger_template<T>::count() const {
    return log_entries_.size();
}

template<typename T>
std::vector<std::pair<std::string, T>> logger_template<T>::contains(const T &data) {
    std::vector<std::pair<std::string, T>> result;
    for (const auto &l: log_entries_) {
        if (l.second == data) {
            result.push_back(l);
        }
    }
    return result;
}


