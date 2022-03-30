#pragma once

//math and time for random pivot
#include <math.h>
#include <time.h>

void swap(int *a, int *b);

// MERGE SORT
void merge(int* arr, int start, int mid, int end);
void mergeSort(int* arr, int start, int end);

//QUICKSORT
int partition(int* arr, int start, int end);
void quickSort(int* arr, int start, int end);

//--TO INTROSORT--//
//HEAPSORT
void heapify(int* arr, int size, int idx);
void heapSort(int* arr, int size);
//INSERTION
void insertionSort(int* arr, int size);

//INTROSORT
void introSort(int* arr, int start, int end, int maxDepth);