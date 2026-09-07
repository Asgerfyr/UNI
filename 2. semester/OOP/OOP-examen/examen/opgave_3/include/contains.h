#pragma once


template<typename C, typename E>
bool contains(const C &container, const E &element) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (*it==element) return true;
    }
    return false;
}
