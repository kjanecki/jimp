
project(arabicroman)

set(HEDEAR_FILES ArabicRoman.h)
set(SOURCE_FILES ArabicRoman.cpp)

add_library(libarabicroman STATIC ${SOURCE_FILES})
target_include_directories(libarabicroman PUBLIC .)
