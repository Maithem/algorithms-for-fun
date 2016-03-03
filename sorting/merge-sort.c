#include <stdio.h>

/**
  A merge sort implementation that has space complexity of
  O(n). This implementation has limitations imposed by the
  stack (i.e. ulimit -s), because the recursion depth and
  the work buffer must fit on the stack.

  @author Maithem
  @date   3/2/2016

*/

typedef unsigned int u_i;

void merge(int arr[], u_i start1, u_i end1, u_i start2, u_i end2) {
  u_i len1 = end1 - start1 + 1;
  u_i len2 = end2 - start2 + 1;
  u_i work_len = len1 + len2;
  int work[work_len];
  int work_ind, ind1 = start1, ind2 = start2;

  for (work_ind = 0; work_ind < work_len; work_ind++) {
    if (ind1 > end1) {
      work[work_ind] = arr[ind2];
      ind2++;
    } else if (ind2 > end2) {
      work[work_ind] = arr[ind1];
      ind1++;
    } else if (arr[ind1] < arr[ind2]) {
      work[work_ind] = arr[ind1];
      ind1++;
    } else {
      work[work_ind] = arr[ind2];
      ind2++;
    }
  }

  // copy back the sorted partition
  for (work_ind = 0; work_ind < work_len; work_ind++)
    arr[start1 + work_ind] = work[work_ind];
}

void sort(int arr[], u_i start, u_i end) {
  if (end - start == 0) return;

  u_i mid = (start + end) / 2;
  sort(arr, start, mid);
  sort(arr, mid + 1, end);
  merge(arr, start, mid, mid+1, end);
}

int main() {
  int arr[12] = {2, 13, 12, 16, 15, 4, 17, 8, 1, 18, 14, 9};
  sort(arr, 0, 11);
  int ind;
  // TODO(Maithem) create a test driver that runs tests against
  // different sorting methods with random inputs of varying lengths.
  for (ind = 0; ind < 12; ind++) printf("%d, ", arr[ind]);
  printf("\n");
  return 0;
}
