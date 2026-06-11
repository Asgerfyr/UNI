add_executable(Opgave_3
        src/opgave_3.cpp
        src/tests.cpp
        src/data_collector.cpp
        src/unique_sorted_collector.cpp
        src/csv_unique_sorted_collector.cpp
        src/json_collector.cpp)

target_include_directories(Opgave_3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)