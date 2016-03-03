#include <stdio.h>

/**

  Insertion sort implementation.

  Note: Although insertion sort has a worst-case running time of O(n^2),
        it can out perform other O(nlogn) algorithms for smaller inputs.
        Insertion sort also has better best-case performance than merge
        sort and selection sort.

        Insertion sort might use less comparisons than selection
        sort, but the latter uses less "swap" operations. In other
        words, if writes are expensive, then using selection sort
        might be advantageous.

  @auther Maithem
  @date   3/3/2016

*/


typedef unsigned int u_i;

void insertion_sort(int arr[], u_i len) {

  // arr is trivially sorted because it only has one element
  if (len == 1) return;

  u_i ind;

  for (ind = 1; ind < len; ind++) {
    int key = arr[ind];
    int sub_ind = ind - 1;

    while (sub_ind >= 0 && key < arr[sub_ind]) {
      // shift element to the right
      arr[sub_ind + 1] = arr[sub_ind];
      sub_ind--;
    }

    arr[sub_ind + 1] = key;
  }
}


int main() {
  int arr[12] = {2, 13, 12, 16, 15, 4, 17, 8, 1, 18, 14, 9};
  insertion_sort(arr, 12);
  int ind;
  for (ind = 0; ind < 12; ind++) printf("%d, ", arr[ind]);
  printf("\n");
  return 0;
}
