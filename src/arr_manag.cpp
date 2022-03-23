#include "arr_manag.hh"

#include <fstream>

bool RunTest(unsigned int noElems, int sortLvl) {

    int* sortArr = InitArr(noElems);
    SortToLvl(sortArr, sortLvl, noElems);

    // for (int i=0; i<100; ++i) {
    //     std::cout << i+1 << ". " << sortArr[i] << std::endl;
    // }

    auto t_start = std::chrono::steady_clock::now();

    SortToLvl(sortArr, 1000, noElems);
    auto t_end = std::chrono::steady_clock::now();
    auto duration_t = t_end - t_start;
    float sortTime = std::chrono::duration <double> (duration_t).count();

    delete[] sortArr;

    WriteToReg(noElems, sortLvl, sortTime);
    return false;
}

int* InitArr(unsigned int size) {
    srand( (unsigned)time( NULL ) );

    int *tosort = new int[size];

    for(unsigned int i=0; i<size; ++i) {
	    tosort[i] = (rand() % 65537) - 32768;
    }

    return tosort;
}

void SortToLvl(int arr[], int lvl, int size) {

    int lastElem = size*lvl/1000;

    int i, j;
    for (i = 0; i < lastElem; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}


bool WriteToReg(int noElems, int sortLvl, float time) {
    std::ofstream Register(REGISTER_FILE, std::ios_base::app);

    float sortPercent = sortLvl*0.1;

    Register << "Size:" << noElems << "\tInitially sorted:" 
             << sortPercent << "%\tTime:" << time << std::endl;

    Register.close();
}