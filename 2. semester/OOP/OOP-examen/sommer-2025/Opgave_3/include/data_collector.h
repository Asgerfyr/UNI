#pragma once

#include <utility>
#include <string>
#include <vector>

class data_collector {
public:
    void receive(double value);

    std::string print();

protected:
    virtual std::vector<double> prepare() const = 0; 
    virtual void collect(double value) = 0; 
    virtual bool filter(double value) const = 0; 
    virtual std::string format(double value) const = 0; 

};