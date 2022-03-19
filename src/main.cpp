#include <iostream>
#include <chrono>

#include "arrays.hh"

int main() {
    auto t_start = std::chrono::steady_clock::now();
    

    SrtArr<int, 1000> first;
    std::cout << first[2] << std::endl;

    
    auto t_end = std::chrono::steady_clock::now();
    auto duration_t = t_end - t_start;
    std::cout << "\tDuration time: " << std::chrono::duration <double> (duration_t).count() << "s\n";


    return 0;
}

