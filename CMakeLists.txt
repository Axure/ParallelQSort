cmake_minimum_required(VERSION 3.12)
project(ParallelQSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(ParallelQSort examples/main.cpp src/insertionSort.cpp src/insertionSort.h)
target_link_libraries(ParallelQSort pthread)

add_executable(ParallelTest examples/test.cpp src/insertionSort.cpp src/insertionSort.h)
target_link_libraries(ParallelTest pthread)

add_executable(SingleThreadedQSort examples/SingleThreadedQSort.cpp src/insertionSort.cpp src/insertionSort.h)

add_library(insertionSort src/insertionSort.h src/insertionSort.cpp)

add_library(quickSort src/quickSort.h src/quickSort.cpp)
target_link_libraries(quickSort insertionSort)

add_library(parallelQuickSort src/parallelQuickSort.h src/parallelQuickSort.cpp)
target_link_libraries(parallelQuickSort insertionSort pthread)

add_executable(insertionSortTest test/insertionSortTest.cpp lib/catch.hpp)
target_link_libraries(insertionSortTest insertionSort)

add_executable(quickSortTest test/quickSortTest.cpp lib/catch.hpp)
target_link_libraries(quickSortTest quickSort parallelQuickSort)
