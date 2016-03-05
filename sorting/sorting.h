#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <stdio.h>

typedef unsigned int u_i;

void insertion_sort(int arr[], u_i len);

void quick_sort(int arr[], u_i len);

void merge_sort(int arr[], u_i len);

#endif