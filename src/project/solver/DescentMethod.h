#ifndef DescentMethod 
#define DescentMethod

#include "../matrix/CSR/CSR.h"

template<typename T>
std::pair<std::vector<T>, std::pair<size_t, std::vector<double>>> Steepest_descent_method
(const std::vector<T>& x_0, const std::vector<T>& b, double accuracy, CSR<T> matrix) 
{
    std::vector<T> x = x_0;
    std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * x[i];
    size_t count = 0;
    std::vector<double> nev{std::sqrt(r * r)};
    std::vector<T> Ar(x_0.size());
    double alpha;
    while (nev[count] > accuracy) {
        std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        Ar[i] = matrix.matrix[i].value * r[i];
        
        alpha = r * r / (r * Ar);
        x = x + alpha * r;
        r = r - alpha * Ar;
        nev.push_back(std::sqrt(r * r));
        count++;
    }
    return std::make_pair(x, std::make_pair(count, nev));
}

#endif