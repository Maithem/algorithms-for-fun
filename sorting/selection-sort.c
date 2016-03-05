#include "sorting.h"

/**
  Selection sort has running time of O(n^2) and O(1)
  space complexity. It works by the intuitive principle
  of iteratively selecting the next min value linearly,
  as it builds up the array from 0 to n - 1.

  @author Maithem
  @date   3/5/2016
 
*/

// TODO(Maithem) factor out swap
void swap1(int *a, int *b) {
  if (*a == *b) return;
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void selection_sort(int arr[], u_i len) {
    for(u_i x = 0; x < len; x++) {
        u_i new_min = x;
        for(u_i y = x + 1; y < len; y++){
            if(arr[y] < arr[new_min]) {
                new_min = y;
            }
        }
        // move new min into the correct position
        swap1(&arr[x], &arr[new_min]);
    }
}
