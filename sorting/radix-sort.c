#include "sorting.h"

/**
 *  Radix sort works by making multiple passes on the array.
 *  On each pass radix sort will sort the array based on the i-th
 *  bit. For example, if the numbers are of 32-bit width, it will
 *  make 32 passes each time running counting sort on the i-th bit.
 *  Radix sort runs in O(OW) time and space complexity of O(w + N),
 *  where W is the width of the numbers.
 *
 *  Radix sort has two variations, one, sorting by the least significant
 *  digit to the most significant digit. Second, the reverse of the first.
 *  In the case of the first variation, numbers are sorted in increasing order.
 *  In the second case, numbers are lexicographically sorted based on their
 *  binary representation. For example, numbers 1 to 10 would be sorted as:
 *  1 to 10 would be output as 1, 10, 2, 3, 4, 5, 6, 7, 8, 9.
 *
 *  @author Maithem
 *
 **/

unsigned int BYTE_IND;


int get_byte(int arr[], int ind) {
    // Isolate byte based on ind. This can be done directly
    // by a linear function, but i will leave this switch case
    // for readability
    switch( BYTE_IND ) {
        case 0:
            return (arr[ind] & 0x000000ff);
            break;
        case 1:
            return (arr[ind] & 0x0000ff00) >> 2 * 4;
            break;
        case 2:
            return (arr[ind] & 0x00ff0000) >> 4 * 4;
            break;
        case 3:
            return (arr[ind] & 0xff000000) >> 6 * 4;
            break;
    }
    return arr[ind];
}

void radix_sort(int arr[], u_i len) {
    for (int x = 0; x < sizeof(int); x++) {
        BYTE_IND = x;
        generic_counting_sort(arr, len, get_byte);
    }
}