add_executable(Opgave_2 src/opgave_2.cpp src/logger.cpp src/tests.cpp src/log_entry.cpp)

target_include_directories(Opgave_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)