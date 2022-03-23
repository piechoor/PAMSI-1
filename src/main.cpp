#include <iostream>

#include "arr_manag.hh"

#define ARR_SIZE 1000000


int main() {

    const int arrSize[] = {10000, 10000, 50000, 100000, 500000, 1000000};
    const int sortLvl[] = {300, -1000, 250, 500, 750, 950, 990, 997}; //sort level per mil

    RunTest(arrSize[0], sortLvl[0]);

    return 0;
}

