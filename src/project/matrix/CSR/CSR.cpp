#include "CSR.h"

template<typename T>
CSR<T>::CSR(std::vector<std::vector<T>> a) {
    std::cout<<"xuy";
    size = 0;
    matrix.resize(1);
	for(size_t i = 0; i < a.size(); i++) {
        for(size_t j = 0; j < a[i].size(); j++)
            if (a[i].value != 0) {
                matrix[i].i = i;
                matrix[i].j = j;
                matrix[i].value = a[i][j];
                size++;
                matrix.resize(matrix.size() + 1);
            }
    }
}

template<typename T>
[[nodiscard]] int CSR<T>::sizeMatrix() {
    return size;
}

template<typename T>
size_t CSR<T>::returnNumb(int i, int j) {
    if(j == 0)
        return matrix[i].i;
    if(j == 1)
        return matrix[i].j;
    if(j == 2)
        return matrix[i].value;
}