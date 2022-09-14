
file(GLOB_RECURSE all_srcs *.cpp)

add_executable(KeySync ${all_srcs})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

if(APPLE)
    target_link_libraries(KeySync PRIVATE "-framework ApplicationServices")
endif()