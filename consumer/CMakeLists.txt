cmake_minimum_required(VERSION 3.18)
project(consumer_project LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 17)

# if we want to use the installed omp_lib
find_package(omp_lib REQUIRED)

# if we want to build omp_lib as part of this project
# add_subdirectory(${PROJECT_SOURCE_DIR}/../ ${PROJECT_SOURCE_DIR}/omp_lib)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC omp_lib)
