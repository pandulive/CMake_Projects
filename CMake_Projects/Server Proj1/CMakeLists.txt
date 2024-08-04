cmake_minimum_required(VERSION 3.1...3.29)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
add_executable(${PROJECT_NAME} panda.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

