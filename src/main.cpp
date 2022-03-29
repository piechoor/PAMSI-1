#include <iostream>
#include "arr_manag.hh"


int main() {

    const int arrSize[] = {10, 10000, 50000, 100000, 500000, 1000000};
    const float sortLvl[] = {0, 25, 50, 75, 95, 99, 99.7, -100}; //sort level percentage

    std::ofstream Register(REGISTER_FILE, std::ios_base::app);

    for (int i=0; i<8; ++i) {
        Register << "stopnien posortowania: " << sortLvl[i] << std::endl;
        RunTest(arrSize[2], sortLvl[i]);
    }

    //RunTest(arrSize[0], sortLvl[0]);
    
    Register.close();

    return 0;
}
