project(reversestring)

set(HEDEAR_FILES ReverseString.h)
set(SOURCE_FILES ReverseString.cpp)

add_library(libreversestring STATIC ${SOURCE_FILES})
target_include_directories(libreversestring PUBLIC .)

add_executable(reverse_string ${SOURCE_FILES} main.cpp)

target_link_libraries(reverse_string libreversestring)

