#pragma once

#include <set>
#include "unique_sorted_collector.h"


class csv_unique_sorted_collector{
public:
    explicit csv_unique_sorted_collector(double upper_limit);

protected:


private:
    double upper_limit_;
};