#include "arr_manag.hh"
#include "algorithms.hh"

#define SHOW_ARRAY true

bool RunTest(int noElems, float sortLvl) {
    for (int i=0; i<1; ++i) {
        int* sortArr = InitArr(noElems, sortLvl);

        if(SHOW_ARRAY) {
            for (int i=0; i<noElems; ++i) {
                std::cout << i+1 << ". " << sortArr[i] << std::endl;
            }
        }

        auto t_start = std::chrono::steady_clock::now();
        
        //quickSort(sortArr, 0, noElems-1);
        //mergeSort(sortArr, 0, noElems-1);
        //heapSort(sortArr, noElems);

        auto t_end = std::chrono::steady_clock::now();

        if(SHOW_ARRAY) {
            for (int i=0; i<noElems; ++i) {
                std::cout << i+1 << ". " << sortArr[i] << std::endl;
            }
        }

        auto duration_t = t_end - t_start;
        float sortTime = std::chrono::duration <double> (duration_t).count();

        delete[] sortArr;

        WriteToReg(noElems, sortLvl, sortTime);

    }
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
        tosort[i] = (rand() % size);
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
        Register << "Size:" << noElems << "\tInitially sorted:" 
                << (int)sortLvl << "%\tTime:" << time_s << "s " <<
                time_ms << "ms " << std::endl;
    else Register << time << std::endl;

    Register.close();
}