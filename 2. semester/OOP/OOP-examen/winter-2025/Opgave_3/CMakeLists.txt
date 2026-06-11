
add_executable(Opgave_3
        src/opgave_3.cpp
        src/loan.cpp
        src/annuity_loan.cpp
        src/serial_loan.cpp
        src/account.cpp
        src/test_annuity_loan.cpp
        src/test_serial_loan.cpp
        src/test_account.cpp
)

target_include_directories(Opgave_3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)