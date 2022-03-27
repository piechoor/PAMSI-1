#include <iostream>
#include "arr_manag.hh"


int main() {

    const int arrSize[] = {1000000, 10000, 50000, 100000, 500000, 1000000};
    const float sortLvl[] = {25, -100, 25, 50, 75, 95, 99, 99.7}; //sort level percentage

    RunTest(arrSize[0], sortLvl[0]);

    return 0;
}

