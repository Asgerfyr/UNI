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
    measurements_template<double> m;
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

void test_template_measurements_on_temperature() {
    measurements_template<temperature> m;
    m.add(temperature{10});
    m.add(temperature{20});
    m.add(temperature{60});
    m.add(temperature{20});
    m.add(temperature{10});
    m.add(temperature{30});

    std::cout << "Max:" << m.max() << "\n";
    std::cout << "Average:" << m.average() << "\n";
    std::cout << "Latest:" << m.latest() << "\n";
    std::cout << "Sorted:\n";
    for (const auto &d: m.sorted()) {
        std::cout << d << ",";
    }
}

