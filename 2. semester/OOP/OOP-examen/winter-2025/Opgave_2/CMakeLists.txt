
add_executable(Opgave_2
        src/opgave_2.cpp
        src/int_container.cpp
        src/test_container_template.cpp
        src/test_int_container.cpp
        src/person.cpp
        src/string_writer.cpp
        src/test_string_writer.cpp
        src/test_string_writer_template.cpp
)

target_include_directories(Opgave_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)