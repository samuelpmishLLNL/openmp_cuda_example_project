cmake_minimum_required(VERSION 3.18)
project(example_omp_project LANGUAGES CXX)

set(lib_dest "lib/omp_lib")
set(include_dest "include/omp_lib")

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)

message(${OpenMP_CXX_FLAGS})

add_library(omp_lib lib.cpp)
if (ENABLE_CUDA)
  enable_language(CUDA)
  target_sources(omp_lib PRIVATE lib.cu)
  set_target_properties(omp_lib PROPERTIES CUDA_ARCHITECTURES "70")

  # don't manually specify flags (!):
  #target_compile_options(omp_lib PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:-Xcompiler=${OpenMP_CXX_FLAGS}>)
endif()

# just link the target with openmp
target_link_libraries(omp_lib PUBLIC OpenMP::OpenMP_CXX)
target_include_directories(omp_lib PUBLIC
  $<INSTALL_INTERFACE:${include_dest}>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
)

install(FILES lib.hpp DESTINATION "${include_dest}")
install(TARGETS omp_lib DESTINATION "${lib_dest}")

install(TARGETS omp_lib EXPORT omp_lib DESTINATION "${lib_dest}")
install(EXPORT omp_lib DESTINATION "${lib_dest}")

install(FILES omp_lib-config.cmake DESTINATION ${lib_dest})

# this is for testing
add_executable(omp_test main.cpp)
target_link_libraries(omp_test PUBLIC omp_lib)
