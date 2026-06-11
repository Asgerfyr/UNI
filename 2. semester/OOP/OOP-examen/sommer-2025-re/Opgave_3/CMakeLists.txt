add_executable(Opgave_3
        src/opgave_3.cpp
        src/tests.cpp
        src/ascii_letter.cpp
        src/ascii_text.cpp
        src/letter_factory.cpp
        src/abstract_ascii_art.cpp
)

target_include_directories(Opgave_3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)