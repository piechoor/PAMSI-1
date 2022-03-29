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


void doHeap(int* arr, int start, int end) {

    // int max = idx, leftChild = 2*idx+1, rightChild = 2*idx+2;
    
    // if (leftChild < size && arr[idx] < arr[leftChild])
    //     max = leftChild;

    // if (rightChild < size && arr[max] < arr[rightChild])
    //     max = rightChild;

    // if (max!=idx) {
    //     swap(&arr[idx], &arr[max]);
    //     heapify(arr, size, max);
    // }
    int save = arr[start];
	while (start <= end /2) {
		int k = 2* start;
		while ( k < end && arr[k] <arr[k+1])
			++k;
		if( save >= arr[k])
			break;
		arr[start] = arr[k];
		start = k;
	}
	arr[start] = save;
}

void heapSort(int* arr, int start, int end) {
    //int size = end-start;
    // for (int i=(end-1))/2-1; i>=start; --i)
    //     doHeap(arr, size, i);

    // for (int i=size-1; i>=start; --i) {
    //     swap(&arr[start], &arr[i]);
    //     --size;
    //     doHeap(arr, size, start);
    // }
    int i;
	for(int i = (end-1) / 2; i >= start; i--){
		doHeap( arr, i , end-1);
	}
	for( i=end-1; i>start; i --){
		swap( &arr[i], &arr[start]);
		doHeap(arr, start, i-1);
	}
}

void insertionSort(int* arr, int start, int end) {
    for (int i=start; i<=end; ++i) {
        int j=i;
        while (j>start && arr[j-1] > arr[j]) {
            swap(&arr[j], &arr[j-1]);
            --j;
        }
    }
} 

void quickSort(int* arr, int start, int end) {

    int pivot = arr[(start+end)/2]; //choosing pivot in the middle
    int s=start, e=end;

    while (s<=e) {
        while (arr[s]<pivot)
            ++s;
        while (arr[e]>pivot)
            --e;
        if (s<=e) {
            swap(&arr[s], &arr[e]);
            ++s; --e;
        }
    }

    if (start<e)
        quickSort(arr,start,e);
    if (end>s) 
        quickSort(arr,s,end);
}

void introSort(int* arr, int start, int end, int maxDepth) {
    int size = end-start;

    if (size<16) {
        //std::cout << "INSERTION activated" << size << std::endl;
        insertionSort(arr, start, end);
    }
    // else if (maxDepth==0) {
    //     heapSort(arr, start, end);
    //     //std::cout << "HEAP activated " << size << std::endl;
    // }
    else {
        //std::cout << "QUICK activated " << maxDepth << std::endl;
        int pivot = arr[(start+end)/2]; //choosing pivot in the middle
        int s=start, e=end;
        while (s<=e) {
            while (arr[s]<pivot)
                ++s;
            while (arr[e]>pivot)
                --e;
            if (s<=e) {
                swap(&arr[s], &arr[e]);
                ++s; --e;
            }
        }
        if (start<e)
            introSort(arr,start,e,maxDepth-1);
        if (end>s) 
            introSort(arr,s,end,maxDepth-1);
    }
}