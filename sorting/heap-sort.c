#include "sorting.h"

/**

  Sorting using a heap encoded as an array is a
  very clever idea, it combines merge sort's
  O(nlogn) running time and quick sort's O(1)
  space complexity.

  @author Maithem

*/

u_i parent(u_i i) {
    // No need to floor, the quotient is
    // always equal to the floor for positive
    // integer division
    return i/2;
}

u_i left(u_i i) {
    return i * 2 + 1;
}

u_i right(u_i i) {
    return i * 2 + 2;
}

void bubble_down(int arr[], u_i len, u_i i) {
    u_i l = left(i);
    u_i r = right(i);
    u_i max_i = i;

    // find the max of i, left(i) and right(i)

    if (l < len && arr[l] >= arr[i]) {
        max_i = l;
    }

    if (r < len && arr[r] >= arr[max_i]) {
        max_i = r;
    }

    if (max_i != i) {
        // swap i with its max child
        //printf("swapping %d and %d\n", arr[i], arr[max_i]);
        int temp = arr[i];
        arr[i] = arr[max_i];
        arr[max_i] = temp;
        bubble_down(arr, len, max_i);
    }
}

void build_heap(int arr[], u_i len) {
    // Give a binary tree encoded in an array,
    // we know the the leafs lie in arr[len/2 + 1 ... len]
    for (int x = (len - 1) / 2; x >= 0 ; x--) {
        bubble_down(arr, len, x);
    }
}

void heap_sort(int arr[], u_i len) {
    // Build heap
    build_heap(arr, len);
    u_i dec_len = len;
    // start sorting the array from right-to-left
    for (int x = 0; x < len; x++) {
        // Swap max element (root) with the right
        // most index
        int temp = arr[len - x - 1];
        arr[len - x - 1] = arr[0];
        arr[0] = temp;
        // The swap might of broken the max-heap
        // property, bubble down to assert the
        // heap's integrity
        bubble_down(arr, --dec_len, 0);
    }
}
