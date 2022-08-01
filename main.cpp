#include "lib.hpp"

#include <iostream>

int main() { 
  foo(); 

  bar([](){
    std::cout << "hello world (bar)" << std::endl;
  });
}
