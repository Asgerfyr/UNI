#include "json_collector.h"

json_collector::json_collector(const std::string &value_name, double low, double high) : value_name_(value_name),
                                                                                         range_(std::pair(low, high)) {}

