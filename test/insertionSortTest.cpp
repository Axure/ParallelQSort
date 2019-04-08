#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../lib/catch.hpp"
#include "../src/insertionSort.h"

unsigned int Factorial(unsigned int number) {
  return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]") {
  REQUIRE(Factorial(1) == 1);
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
  REQUIRE(Factorial(10) == 3628800);
}


TEST_CASE("Insertion sort should be correct") {
  int a[5] = {1, 2, 3, 7, 5};

  insertionSort(a, 0, 5);

  REQUIRE(a[3] == 5);
  REQUIRE(a[4] == 7);
}
