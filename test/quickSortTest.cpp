#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../lib/catch.hpp"
#include "../src/quickSort.h"
#include "../src/parallelQuickSort.h"
#include <chrono>
#include <iostream>

TEST_CASE("Quick sort should be correct") {
  int a[8] = {1, 2, 3, 7, 5, 12, 8, 9};

  quickSort(a, 0, 8);

  REQUIRE(a[0] == 1);
  REQUIRE(a[1] == 2);
  REQUIRE(a[2] == 3);
  REQUIRE(a[3] == 5);
  REQUIRE(a[4] == 7);
  REQUIRE(a[5] == 8);
  REQUIRE(a[6] == 9);
  REQUIRE(a[7] == 12);
}

TEST_CASE("Parallel quick sort should be correct") {
  int a[8] = {1, 2, 3, 7, 5, 12, 8, 9};

  parallelQuickSort(a, 0, 8);

  REQUIRE(a[0] == 1);
  REQUIRE(a[1] == 2);
  REQUIRE(a[2] == 3);
  REQUIRE(a[3] == 5);
  REQUIRE(a[4] == 7);
  REQUIRE(a[5] == 8);
  REQUIRE(a[6] == 9);
  REQUIRE(a[7] == 12);
}

#define SIZE 17500

TEST_CASE("Sort should do in a short time") {
  int a[SIZE];
  int b[SIZE];

  srand(time(NULL));

  for (int i = 0; i < SIZE; ++i) {
    a[i] = random() % (SIZE * 100);
    b[i] = a[i];
  }

  {
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    quickSort(a, 0, SIZE);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::cout << duration << std::endl;
  }

  {
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    parallelQuickSort(b, 0, SIZE);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto durationParallel = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::cout << durationParallel << std::endl;
  }

  for (int i = 0; i < SIZE - 1; ++i) {
    REQUIRE(a[i] <= a[i + 1]);
    REQUIRE(b[i] <= b[i + 1]);
  }
}
