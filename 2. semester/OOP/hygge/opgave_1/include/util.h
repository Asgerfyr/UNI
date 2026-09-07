#include <cmath>

template<typename T>

T sigmoid(T x){
    if (x > 5) return 1.0f;
    if (x < -5) return 0.0f;
    return 0.5f * (x / (1.0f + std::abs(x)) + 1.0f);
}