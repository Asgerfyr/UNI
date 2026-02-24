//
// Created by Asger on 22/02/2026.
//

#ifndef L4_DIE_H
#define L4_DIE_H

#include <random>
#include <vector>
#include <string>

class Die {
public:
    Die();
    void roll();
    int get_value()const;

    void reset_total();
    std::string get_total() const;

    int get_total_throws()const;

    std::vector<double> get_frequency() const;

    double get_mean() const;

private:
    int value_;
    static inline int total_throws_ = 0;
    static inline std::vector<int>total_{0,0,0,0,0,0};
    static inline std::random_device rd_; //seed gen
    static inline std::mt19937 mt_{Die::rd_()};//random seed gen
    static inline std::uniform_int_distribution<int> dist_{1,6};

    void inc_total();
};



#endif //L4_DIE_H