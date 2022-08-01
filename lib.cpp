#include "lib.hpp"

#include <omp.h>

#include <iostream>

void foo() {
  #pragma omp parallel
  {
    std::cout << "hello world (foo)" << std::endl;
  }
}
