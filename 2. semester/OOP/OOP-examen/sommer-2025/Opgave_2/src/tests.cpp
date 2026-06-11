#include "tests.h"
#include "temperature.h"
#include "measurements.h"
#include "measurements_template.h"

void test_measurements() {
    measurements m;
    m.add(10);
    m.add(20);
    m.add(60);
    m.add(20);
    m.add(10);
    m.add(30);

    std::cout << "Max:" << m.max() << "\n";
    std::cout << "Average:" << m.average() << "\n";
    std::cout << "Latest:" << m.latest() << "\n";
    std::cout << "Sorted:\n";
    for (const auto &d: m.sorted()) {
        std::cout << d << ",";
    }
}

void test_template_measurements() {
}

void test_template_measurements_on_temperature() {
}

