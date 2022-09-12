
file(GLOB_RECURSE all_srcs *.cpp)

add_executable(KeySync ${all_srcs})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)