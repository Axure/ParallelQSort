//
// Created by zhenghu on 19-4-8.
//

#include "insertionSort.h"

void insertionSort(int array[], int start, int end) {
  for (int i = start; i < end; ++i) {
    for (int j = i; j > 0 && array[j - 1] > array[j]; --j) {
      std::swap(array[j], array[j - 1]);
    }
  }
}
