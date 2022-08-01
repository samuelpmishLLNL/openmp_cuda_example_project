#include <iostream>

__global__ void my_kernel() {}

void bar() {
  #pragma omp parallel
  {
    std::cout << "hello world (bar)" << std::endl;
  }
}
