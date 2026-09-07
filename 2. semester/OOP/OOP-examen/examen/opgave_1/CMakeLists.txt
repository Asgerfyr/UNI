
add_executable(opgave_1 src/opgave_1.cpp src/matrix_1.cpp src/test_1.cpp)


target_include_directories(opgave_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)