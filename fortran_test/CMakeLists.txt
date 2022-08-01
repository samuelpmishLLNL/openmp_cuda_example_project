cmake_minimum_required(VERSION 3.18)
project(fortran_project LANGUAGES CXX FORTRAN)

# if we want to use the installed omp_lib
find_package(omp_lib REQUIRED)

# if we want to build omp_lib as part of this project
# add_subdirectory(${PROJECT_SOURCE_DIR}/../ ${PROJECT_SOURCE_DIR}/omp_lib)

add_executable(main main.f90)
target_link_libraries(main PUBLIC omp_lib)
