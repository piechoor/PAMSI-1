#pragma once
#include <array>

template <typename T, unsigned int R>
class SrtArr {
    private:
        std::array<T, R> arr;

    public:
        SortArray() {
            arr.fill(44);
        }

    T operator [] (unsigned int indeks);
};

template <typename T, unsigned int R>
T SrtArr<T, R>::operator [] (unsigned int idx) {
    return arr.at(idx);
}