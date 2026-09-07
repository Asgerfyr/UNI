
add_executable(opgave_4 src/opgave_4.cpp src/message.cpp src/test_4.cpp src/email.cpp src/sms.cpp src/dispatcher.cpp)

target_include_directories(opgave_4 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)