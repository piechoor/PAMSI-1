#include <iostream>
#include "arr_manag.hh"


int main() {

    const int arrSize[] = {10000, 50000, 100000, 500000, 1000000}; 
    int sizeSIZE = sizeof(arrSize)/sizeof(arrSize[0]);
    const float sortLvl[] = {-100, 0, 25, 50, 75, 95, 99, 99.7};
    int sizeLVL = sizeof(sortLvl)/sizeof(sortLvl[0]);

    std::ofstream Register(REGISTER_FILE, std::ios_base::app);

    //Register << "MERGESORT:" << std::endl;
    //Register << "QUICKSORT" << std::endl;
    Register << "INTROSORT" << std::endl;

    for (int i=0; i<sizeSIZE; ++i) {
        for (int j=0; j<sizeLVL; ++j)
            RunTest(arrSize[i], sortLvl[j]);
        Register << std::endl;
    }
    Register.close();

    return 0;
}
