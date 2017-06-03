
project(tree)

set(HEDEAR_FILES Tree.h TreeIterators.h)
set(SOURCE_FILES Tree.cpp TreeIterators.cpp)

add_library(libtree STATIC ${SOURCE_FILES})
target_include_directories(libtree PUBLIC .)

add_library(libtreeiterators STATIC ${SOURCE_FILES})
target_include_directories(libtreeiterators PUBLIC .)

add_executable(tree ${SOURCE_FILES} main.cpp)

target_link_libraries(tree libtree)