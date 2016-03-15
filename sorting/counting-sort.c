#include "sorting.h"

/*
  Counting sort is a non-comparison sorting algorithm, it
  has a running time and space complexity of O(n + k), where
  n is the length of the input array and k is the max number
  in the array.
  
  Counting sort only works for non-negative integers, but can
  be generalized to work with negative integers. Consider the
  tweak where the input is shifted upwards by a constant factor
  (the min element in the array), then we can run counting sort
  and then shift the resulting array down by the same constant
  factor.
  
  Also, counting sort is a stable sorting, can be unstable if
  the final positioning loop processes the array from left-to-
  right, instead of right-to-left.
  
  Counting sort can have a running time of O(n) if k = n, in
  other words, all elements of the array are distinct.
  
  @author Maithem
  
 **/


int get(int arr[], int ind) {
    return arr[ind];
}

void generic_counting_sort(int arr[], u_i len, int (*get)(int *, int)) {
    // Compute max element in arr
    int max = -1;
    for (int x = 0; x < len; x++) {
        max = get(arr, x) > max ? get(arr, x) : max;
    }
    
    // Create a frequency count array
    int aux[max + 1];
    memset(aux, 0, sizeof(aux));
    for (int x = 0; x < len; x++) {
        aux[get(arr, x)] += 1;
    }

    // Tally freqencies such that the number at index
    // x is the number of ints less then or equal to it.
    for (int x = 1; x < max + 1; x++) {
        aux[x] += aux[x - 1];
    }
    
    // Start placing the numbers in the correct
    // position
    int out[len];
    for (int x = len - 1; x >= 0; x--) {
        out[aux[get(arr, x)] - 1] = arr[x];
        aux[get(arr, x)] -= 1;
    }
    
    // copy back the array
    for (int x = 0; x < len; x++) {
        arr[x] = out[x];
    }
}

void counting_sort(int arr[], u_i len) {
    generic_counting_sort(arr, len, get);
}