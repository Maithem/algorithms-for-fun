#include <stdio.h>

void swap(int arr[], unsigned int i, unsigned int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printArr(int arr[], unsigned int len) {
    for (int x = 0; x < len; x++) printf("%d ", arr[x]);
    printf("\n");
}

int main() {

    int arr[] = {1, 2, 3};
    unsigned int len = 3;

    unsigned int fact = 1;

    // Compute the factorial
    for (int x = 1; x <= len; x++) fact *= x;

    for (int x = 0; x < fact; x++) {
        unsigned int i = x % (len - 1);
        printArr(arr, len);
        swap(arr, i, i + 1);
    }

    return 0;
}