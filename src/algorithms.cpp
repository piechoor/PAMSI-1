#include "algorithms.hh"

void merge(int* arr, int start, int mid, int end)
{
    //temp arrays' lenghts
    int lenLeft = mid - start + 1;
    int lenRight = end - mid;
  
    int *leftArr = new int[lenLeft]; //temp arrays
    int *rightArr = new int[lenRight]; 
  
    //copying to temp arrays
    for (int i = 0; i<lenLeft; ++i)
        leftArr[i] = arr[start+i];
    for (int i = 0; i<lenRight; ++i)
        rightArr[i] = arr[mid+i+1];
  
    int iterLeft = 0, iterRight = 0, iterArr = start; //iterators for each of arryas 
  
    //writing to final array a smaller number of two arrays and iterating final array and
    //the one that element is from
    while (iterLeft < lenLeft && iterRight < lenRight) {
        if (leftArr[iterLeft] <= rightArr[iterRight]) {
            arr[iterArr] = leftArr[iterLeft];
            ++iterLeft;
        }
        else {
            arr[iterArr] = rightArr[iterRight];
            ++iterRight;
        }
        ++iterArr;
    }
    
    //above loop finishes when one of two arrays are copied, so below we copy the rest
    //of the second one to the final array
    while (iterLeft < lenLeft) {
        arr[iterArr] = leftArr[iterLeft];
        ++iterArr; ++iterLeft;
    }
    while (iterRight < lenRight) {
        arr[iterArr] = rightArr[iterRight];
        ++iterArr; ++iterRight;
    }
}
  
//divides and merges current array recursively  
void mergeSort(int* arr, int start, int end)
{
    if (start >= end) 
        return;
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}