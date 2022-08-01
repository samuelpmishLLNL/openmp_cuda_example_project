#pragma once

void foo();

template < typename callable >
void bar(callable f) {
  #pragma omp parallel
  {
    f();
  }
}
