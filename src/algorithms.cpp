#include "algorithms.hh"

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void merge(int* arr, int start, int mid, int end)
{
    //temp arrays' lenghts
    int lenLeft = mid - start + 1;
    int lenRight = end - mid;
  
    int *leftArr = new int[lenLeft]; //temp arrays
    int *rightArr = new int[lenRight]; 
  
    //copying to temp arrays
    for (int i=0; i<lenLeft; ++i)
        leftArr[i] = arr[start+i];
    for (int i=0; i<lenRight; ++i)
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

    delete[] leftArr; delete[] rightArr;
}
  
//divides and merges passed current array recursively  
void mergeSort(int* arr, int start, int end)
{
    if (start < end) {
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}


int partition(int* arr, int start, int end) {
    int pivot = arr[end]; //pivot - element thats being use for comparison
    int beforePivot = start-1; //points at last element smaller/eq than pivot

    for (int i=start; i<end; ++i) {
        if (arr[i]<=pivot) { //if elem is smaller than pivot put it b4 arr[beforePivot]
            ++beforePivot;
            swap(&arr[beforePivot], &arr[i]);
        }
    }
    //puting pivot after all smaller elements
    swap(&arr[beforePivot+1], &arr[end]);
    
    return (beforePivot+1); //returning pivot index
}

void quickSort(int* arr, int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

void heapify(int* arr, int size, int idx) {

    int max = idx, leftChild = 2*idx+1, rightChild = 2*idx+2;
    
    if (leftChild < size && arr[idx] < arr[leftChild])
        max = leftChild;

    if (rightChild < size && arr[max] < arr[rightChild])
        max = rightChild;

    if (max!=idx) {
        swap(&arr[idx], &arr[max]);
        heapify(arr, size, max);
    }
}

void heapSort(int* arr, int size) {
    for (int i=size/2-1; i>=0; --i)
        heapify(arr, size, i);

    for (int i=size-1; i>=0; --i) {
        swap(&arr[0], &arr[i]);
        --size;
        heapify(arr, size, 0);
    }
}

void insertionSort(int* arr, int size) {
    for (int i=1; i<size; ++i) {
        int j=i;
        while (j>0 && arr[j-1] > arr[j]) {
            swap(&arr[j], &arr[j-1]);
            --j;
        }
    }
}