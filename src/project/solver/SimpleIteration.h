#ifndef SimpleIteration
#define SimpleIteration

#include "../matrix/CSR/CSR.h"

template<typename T>
std::pair<std::vector<double>, std::pair<size_t, std::vector<double>>> Simple_iteration_method
(const std::vector<T>& x_0, const std::vector<T>& b, double tau, double accuracy, CSR<T> matrix) 
{
    std::vector<T> x = x_0;
    std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * x[i];
    size_t count = 0;
    std::vector<double> nev{std::sqrt(r * r)};
    while (nev[count] > accuracy) {
        std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * x[i];
        x = x + tau * r;
        nev.push_back(std::sqrt(r * r));
        count++;
    }
    return std::make_pair(x, std::make_pair(count, nev));
}


#endif