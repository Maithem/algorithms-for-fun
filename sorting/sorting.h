#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <stdio.h>
#include <string.h>

typedef unsigned int u_i;

void insertion_sort(int arr[], u_i len);

void quick_sort(int arr[], u_i len);

void merge_sort(int arr[], u_i len);

void selection_sort(int arr[], u_i len);

void counting_sort(int arr[], u_i len);

void generic_counting_sort(int arr[], u_i len, int (*get)(int *, int));

void radix_sort(int arr[], u_i len);

void heap_sort(int arr[], u_i len);

#endif