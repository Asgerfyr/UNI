add_executable(Opgave_1 src/opgave_1.cpp src/point.cpp src/square.cpp
        src/tests.cpp)

target_include_directories(Opgave_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)