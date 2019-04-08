//
// Created by zhenghu on 19-4-8.
//

#include "parallelQuickSort.h"
#include "insertionSort.h"
#include <algorithm>
#include <pthread.h>

struct ParallelQuickSortImplArgs {
  int *A;
  int start;
  int end;
};

void *parallelQuickSortImpl(void *rawArgs);

void parallelQuickSort(int A[], int start, int end) {
  ParallelQuickSortImplArgs args = {
      A, start, end
  };
  parallelQuickSortImpl(&args);
}

void *parallelQuickSortImpl(void *rawArgs) {
  ParallelQuickSortImplArgs *args = reinterpret_cast<ParallelQuickSortImplArgs *>(rawArgs);
  if (args->end - args->start < 3) {
    insertionSort(args->A, args->start, args->end);

    return NULL;
  }

  int pivot = args->A[(args->start + args->end - 1) / 2];

  int i = args->start - 1;
  int j = args->end;

  int p = -1;

  do {
    do {
      ++i;
    } while (args->A[i] < pivot);
    do {
      --j;
    } while (args->A[j] > pivot);

    if (i >= j) {
      p = j;
      break;
    }

    std::swap(args->A[i], args->A[j]);
  } while (true);

  pthread_t threadLeft, threadRight;

  ParallelQuickSortImplArgs leftArgs = {
      args->A, args->start, p + 1
  };
  ParallelQuickSortImplArgs rightArgs = {
      args->A, p + 1, args->end
  };

  pthread_create(&threadLeft, NULL, parallelQuickSortImpl, reinterpret_cast<void *>(&leftArgs));
  pthread_create(&threadRight, NULL, parallelQuickSortImpl, reinterpret_cast<void *>(&rightArgs));

  pthread_join(threadLeft, NULL);
  pthread_join(threadRight, NULL);
}
