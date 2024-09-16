cmake_minimum_required(VERSION 3.13)
project(asio-1.28.0)

add_library(asio-1.28.0 INTERFACE)
target_include_directories(asio-1.28.0 INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")


#Define MY_SOURCES to be a list of all the source files for my game 
file(GLOB_RECURSE PROFILER_LIB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
# add_executable(profilerLib_test)
# target_sources(profilerLib_test PRIVATE ${PROFILER_LIB_SOURCES} )
# target_link_libraries(profilerLib_test PUBLIC profilerLib)