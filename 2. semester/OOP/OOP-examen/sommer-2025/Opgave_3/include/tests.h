#pragma once

#include "unique_sorted_collector.h"
//Remove comments /* .. */ when starting implementation
/*
class unique_sorted_collector_test : public unique_sorted_collector {
protected:
    bool filter(double value) const override {
        return true;
    };

    std::string format(double value) const override {
        return std::to_string(value);
    };

};*/

void test_unique_sorted_collector();

void test_csv_unique_sorted_collector();

void test_json_collector();