get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(${SELF_DIR}/${CMAKE_BUILD_TYPE}/omp_lib.cmake)

find_package(OpenMP REQUIRED)
