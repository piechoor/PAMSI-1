#pragma once
#include <iostream>
void swap(int *a, int *b);

// MERGE SORT
void merge(int* arr, int start, int mid, int end);
void mergeSort(int* arr, int start, int end);

//QUICKSORT
int partition(int* arr, int start, int end);
void quickSort(int* arr, int start, int end);

//HEAPSORT
void doHeap(int* arr, int start, int end);
void heapSort(int* arr, int start, int end);

void insertionSort(int* arr, int start, int end);

void introSort(int* arr, int start, int end, int maxDepth);