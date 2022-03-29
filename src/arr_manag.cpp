#include "arr_manag.hh"
#include "algorithms.hh"

#define SHOW_ARRAY false

bool RunTest(int noElems, float sortLvl) {
    

    auto t_start = std::chrono::steady_clock::now();

    for (int i=0; i<1; ++i) {
        
        int* sortArr = InitArr(noElems, sortLvl);

        if(SHOW_ARRAY) {
            for (int i=0; i<noElems; ++i) {
                std::cout << i+1 << ". " << sortArr[i] << std::endl;
            }
        }
        //sortByQuicksort(sortArr, 0, noElems-1);
        //quickSort(sortArr, 0, noElems-1);
        introSort(sortArr, 0, noElems-1, floor(log2(noElems))*2);
        //mergeSort(sortArr, 0, noElems-1);
        //heapSort(sortArr, noElems);
        //insertionSort(sortArr, 0, noElems-1);

        if(SHOW_ARRAY) {
            for (int i=0; i<noElems; ++i) {
                std::cout << i+1 << ". " << sortArr[i] << std::endl;
            }
            if (!isSorted(sortArr, noElems))
                std::cout << "\nTablica NIEposortowana!\n"; 
        }
        if (!isSorted(sortArr, noElems))
            std::cout << "\nTablica NIEposortowana!\n"; 

        delete[] sortArr;
    }
    auto t_end = std::chrono::steady_clock::now();
    auto duration_t = t_end - t_start;
    float sortTime = std::chrono::duration <double> (duration_t).count();
    
    std::cout << "Czas sortowania: " << sortTime << std::endl;

    WriteToReg(noElems, sortLvl, sortTime);

    return false;
}

int* InitArr(int size, float sortLvl) {
    srand( (unsigned)time( NULL ) );
    bool reverse = false;

    if ((int)sortLvl>100 || (int)sortLvl<-100) {
        std::cerr << "Initially sorted level of the array exceeds -100%:100% range." << std::endl;
        exit(0);
    }

    if (sortLvl<0) {
        reverse = true;
        sortLvl = -sortLvl;
    }

    int *tosort = new int[size];
    int noSorted = sortLvl*size*0.01;
    for(int i=0; i<noSorted; ++i) {
        tosort[i] = -size+i;
    }
    for(int i=noSorted; i<size; ++i) {
        tosort[i] = (rand() % size)+1;
    }

    if (reverse) {
        int i=0, j=size-1, temp=0;
        while( i < j){
            //swap
            temp = tosort[i];
            tosort[i] = tosort[j];
            tosort[j] = temp;
            i++;  j--;  
        }
    }
    return tosort;
}

void WriteToReg(int noElems, float sortLvl, float time) {
    std::ofstream Register(REGISTER_FILE, std::ios_base::app);

    int time_s = (int)time;
    int time_ms = (int)((time-time_s)*1000); 

    if (REG_FORM_HUMAN)
        Register << "Size:" << noElems << " Initially sorted:" 
                << (int)sortLvl << "% Time:" << time_s << "s " <<
                time_ms << "ms " << std::endl;
    else Register << time*1000 << std::endl;

    Register.close();
}

bool isSorted(int* arr, int size) {
    for (int i=0; i<size-1; ++i) {
        if (arr[i]>arr[i+1])
            return false;
    }
    return true;
}
