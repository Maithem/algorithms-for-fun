#include <stdio.h>
#include <assert.h>

/**
 *  Simple binary search that has a running time of O(logn) and a
 *  space complexity of O(1). This binary search implementation
 *  can also be abstracted to searching in a problem space of real
 *  numbers.
 *
 *  @author Maithem
 *  
 */

int binary_search(int arr[], int start, int end, const int target) {
    if (end < start) return -1;
    
    int mid = (start + end) / 2;
    if (target == arr[mid]) return mid;
    else if (target < arr[mid]) {
        // Recurse on left sub-problem
        return binary_search(arr, start, mid - 1, target);
    }
    else {
        // Recurse on the right sub-problem
        return binary_search(arr, mid + 1, end, target);
    }
}

int main() {
    int len = 7;
    int arr[] = {0, 1, 2, 3, 4, 5, 6};

    assert(binary_search(arr, 0, len - 1, 0) == 0);
    assert(binary_search(arr, 0, len - 1, 1) == 1);
    assert(binary_search(arr, 0, len - 1, 2) == 2);
    assert(binary_search(arr, 0, len - 1, 3) == 3);
    assert(binary_search(arr, 0, len - 1, 4) == 4);
    assert(binary_search(arr, 0, len - 1, 5) == 5);
    assert(binary_search(arr, 0, len - 1, 6) == 6);
    // Check for the case where the key doesn't exist
    assert(binary_search(arr, 0, len - 1, 7) == -1);
    
    return 0;
}