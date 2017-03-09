project(doublebasepalindromes)

set(HEDEAR_FILES DoubleBasePalindromes.h)
set(SOURCE_FILES DoubleBasePalindromes.cpp)

add_library(libdoublebasepalindromes STATIC ${SOURCE_FILES})
target_include_directories(libdoublebasepalindromes PUBLIC .)

add_executable(double_base_palindromes ${SOURCE_FILES} main.cpp)

target_link_libraries(double_base_palindromes libdoublebasepalindromes)

