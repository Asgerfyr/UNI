file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(Opgave_2 ${SOURCES})

target_include_directories(Opgave_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)