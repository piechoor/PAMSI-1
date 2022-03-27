#include "algorithms.hh"

void merge(int* arr, int idx_l, int idx_m, int idx_r)
{
    int subArr1 = idx_m - idx_l + 1;
    int subArr2 = idx_r - idx_m;
  
    // Create temp arrs
    int *leftArray = new int[subArr1],
         *rightArray = new int[subArr2];
  
    // Copy data to temp arrs leftArray[] and rightArray[]
    for (int i = 0; i < subArr1; i++)
        leftArray[i] = arr[idx_l + i];
    for (int j = 0; j < subArr2; j++)
        rightArray[j] = arr[idx_m + 1 + j];
  
    int indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = idx_l; // Initial index of merged arr
  
    // Merge the temp arrs back into arr[left..right]
    while (indexOfSubArrayOne < subArr1 && indexOfSubArrayTwo < subArr2) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArr1) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArr2) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int* arr, int begin, int end)
{
    if (begin >= end)
        return; // Returns recursively
  
    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}