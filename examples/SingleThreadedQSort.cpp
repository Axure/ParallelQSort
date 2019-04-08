#include <iostream>
#include "../src/insertionSort.h"

void sortBetween(int array[], int start, int end) {
  if (end - start <= 3) {
    insertionSort(array, start, end);
    return;
  }


}

void sort(int array[], int length) {
  sortBetween(array, 0, length);
}

int main() {
  std::cout << "Hello, World!" << std::endl;


  return 0;
}
