#pragma once

void swap(int *a, int *b);

// MERGE SORT
void merge(int* arr, int start, int mid, int end);
void mergeSort(int* arr, int start, int end);

//QUICKSORT
int partition(int* arr, int start, int end);
void quickSort(int* arr, int start, int end);

//HEAPSORT
void heapify(int* arr, int size, int idx);
void heapSort(int* arr, int size);
