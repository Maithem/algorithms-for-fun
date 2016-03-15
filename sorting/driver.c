#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorting.h"


// timer functions

// print report

struct array {
  u_i len;
  int *arr;
};

void print_array(int arr[], u_i len) {
    u_i ind;
    printf("{");
    for(ind = 0; ind < len; ind++) {
        printf("%d, ", arr[ind]);
    }
    printf("}\n");
}

int *copy(int src[], u_i len) {
    int *temp = malloc(sizeof(int)*len);
    memcpy(temp, src, len * sizeof(int));
    return temp;
}

bool equal(int *a, int *b, u_i len){
    bool temp = true;
    int ind;
    for (ind = 0; ind < len; ind++) {
        if (a[ind] != b[ind]) {
            return false;
        }
    }
}

int main() {
    
  u_i len = 12;
  int arr[12] = {2, 13, 12, 16, 15, 4, 17, 8, 1, 18, 14, 9};
  int *temp1 = copy(arr, len);
  insertion_sort(temp1, len);
  int *temp2 = copy(arr, len);
  quick_sort(temp2, len);
  int *temp3 = copy(arr, len);
  merge_sort(temp3, len);
  int *temp4 = copy(arr, len);
  selection_sort(temp4, len);
  int *temp5 = copy(arr, len);
  counting_sort(temp5, len);
  int *temp6 = copy(arr, len);
  heap_sort(temp6, len);
  int *temp7 = copy(arr, len);
  radix_sort(temp7, len);
  
  bool eq = equal(temp1, temp2, len) &
            equal(temp2, temp3, len) &
            equal(temp3, temp4, len) &
            equal(temp4, temp5, len) &
            equal(temp5, temp6, len) &
            equal(temp6, temp7, len);
            
  printf("\x1B[32m""Equal arrays :%s\n""\033[0m", eq ? "true" : "false");
  
  // Free all arrays allocated.
}
