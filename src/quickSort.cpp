//
// Created by zhenghu on 19-4-8.
//

#include "quickSort.h"
#include "insertionSort.h"
#include <algorithm>

void quickSort(int A[], int start, int end) {
  if (end - start < 3) {
    insertionSort(A, start, end);

    return;
  }

  int pivot = A[(start + end - 1) / 2];

  int i = start - 1;
  int j = end;

  int p = -1;

  do {
    do {
      ++i;
    } while (A[i] < pivot);
    do {
      --j;
    } while (A[j] > pivot);

    if (i >= j) {
      p = j;
      break;
    }

    std::swap(A[i], A[j]);
  } while (true);

  quickSort(A, start, p + 1);
  quickSort(A, p + 1, end);
}
