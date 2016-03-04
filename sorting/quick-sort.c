#include <stdio.h>


/**

    Quick sort implementation. Quick sort is a very elegant
  algorithm. Quick sort like merge sort uses the divide and
  conquer pattern, but unlike merge sort the divide step
  depends on the data (i.e. pivot value). During recursion,
  the worst possible pivot can cause the divide step to split
  the problem into two subproblems. Namely, a subproblem of
  size n - 1 and an empty subproblem (i.e. size 0). If bad
  pivots are consistently chosen, then the algorithm runs
  in the worst-case scenario, where it has a running time of
  O(n^2). Luckily, we can use randomization to usually make
  the algorithm run in the average case, which has a running
  time of O(nlogn).

  It's also worthy to note that the worst case scenario
  happens when the array is already sorted.

  Also, instead of randomizing the data, the pivot selection
  can be randomized as an optimization.

  @author Maithem
  @date   3/4/2016

*/


typedef unsigned int u_i;

void swap(int *a, int *b) {
  if (*a == *b) return;
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

u_i parition(int arr[], u_i start, u_i end) {
  int ind;
  int pivot = arr[end];
  u_i pivot_ind = start - 1;
  // start moving < values to the left of the
  // boundary
  for (ind = start ; ind <= end - 1; ind++) {
    if (arr[ind] < pivot) {
      swap(&arr[++pivot_ind], &arr[ind]);
    }
  }
  // Move the pivot to the end of the boundary
  swap(&arr[++pivot_ind], &arr[end]);
  return pivot_ind;
}

void quick_sort(int arr[], int start, int end) {

  if (start >= end) return;

  u_i pivot_ind = parition(arr, start, end);
  quick_sort(arr, start, pivot_ind - 1);
  quick_sort(arr, pivot_ind + 1, end);
}

int main() {
  int ind;
  // TODO(Maithem) factor out swap and printing functions
  int arr[12] = {2, 13, 12, 16, 15, 4, 17, 8, 1, 18, 14, 9};
  quick_sort(arr, 0, 11);
  for (ind = 0; ind < 12; ind++) printf("%d, ", arr[ind]);
  printf("\n");
  return 0;
}
