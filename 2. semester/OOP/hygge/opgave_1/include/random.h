#include <random>

class Random{
    public:
    static float get_float(float min, float max){
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<> dist(min,max);
        return dist(gen);
    }
};
