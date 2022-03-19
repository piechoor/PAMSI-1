#include <iostream>
#include <chrono>

int main() {
    auto t_start = std::chrono::steady_clock::now();

    int tab[100000];

    for (int i=0; i<1; ++i) {
        for (int j=0; j<100000; ++j) {
            tab[j] = i+j;
        }
    }
    
    auto t_end = std::chrono::steady_clock::now();
    auto duration_t = t_end - t_start;
    std::cout << "\tDuration time: " << std::chrono::duration <double> (duration_t).count() << "s\n";

    return 0;
}

int CreateArray()