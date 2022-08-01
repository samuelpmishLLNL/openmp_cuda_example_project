# Example CMake project using native CUDA and OpenMP support

To build, follow idiomatic CMake commands:

1. make a build directory
```
mkdir build
cd build
```

2. configure 

with cuda support
```
cmake .. -DENABLE_CUDA=TRUE
```
or without
```
cmake ..
```

3. build
```
cmake --build .
```

4. (optionally) install
```
sudo cmake --install .
```

# Using this CMake project as a dependency in another Project

The `consumer` directory shows the two main ways to use this CMake project as a dependency.

1. first build and install the project by following the instructions above, and then use `find_package()` to locate it

2. clone this CMake project and then have the consumer library do `add_subdirectory` in its CMakeLists.txt

Then (in either case), just do `target_link_libraries(consumer_target PUBLIC omp_lib)`
