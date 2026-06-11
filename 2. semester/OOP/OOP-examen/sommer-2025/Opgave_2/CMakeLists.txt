add_executable(Opgave_2 src/opgave_2.cpp src/measurements.cpp src/temperature.cpp src/tests.cpp)

target_include_directories(Opgave_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)