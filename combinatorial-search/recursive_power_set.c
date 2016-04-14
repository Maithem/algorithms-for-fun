#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
enum { false, true };

// Either gets a new set, or gets a new set and removes
// the element on index i
int *getNew(int arr[], unsigned int len, unsigned int i) {
    int *tmp = malloc(sizeof(int) * len);
    memcpy(tmp, arr, sizeof(int) * len);
    if (i == -1 || i >= len) return tmp;
    tmp[i] = -1;
    return tmp;
}

// Returns the index of the right most element
int right(int arr[], unsigned int len) {
    int ind = -1;
    for (int x = 0; x < len; x++) if (arr[x] != -1) ind = x;
    return ind;
}


void printSet(int arr[], unsigned int len) {
    for (int x = 0; x < len; x++) {
        if (arr[x] != -1) printf("%d ", arr[x]);
    }
    printf("\n");
}

bool isEmpty(int arr[], unsigned int len) {
    for (int x = 0; x < len; x++) {
        if (arr[x] != -1) return false;
    }
    return true;
}

void powerset(int arr[], unsigned int i, unsigned int len) {
    if (i > right(arr, len || isEmpty(arr, len))){
        printSet(arr, len);
        return;
    }

    int *setA = getNew(arr, len, -1);
    int *setB = getNew(arr, len, i);

    powerset(setB, len, i + 1);
    powerset(setA, len, i + 1);

    free(setA);
    free(setB);
}

int main() {
    int arr[] = {1, 2, 3};
    unsigned int len = 3;

    powerset(arr, 0, len);

    return 0;
}