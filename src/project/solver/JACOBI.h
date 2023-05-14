#ifndef JACOBI
#define JACOBI

#include "../matrix/CSR/CSR.h"


template<typename T>
std::pair<std::vector<T>, std::pair<size_t, std::vector<double>>> Jacobi_method(const std::vector<T>& x_0, const std::vector<T>& b, double accuracy, CSR<T> matrix) 
{

    std::vector<T> x0 = x_0;
    std::vector<T> r(matrix.matrix.size());
    for(int i = 0; i < matrix.matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * x_0[i];
    std::vector<T> x(x_0.size());
    size_t count = 0;
    std::vector<double> nev {sqrt(r * r)};
    while (nev[count] > accuracy) {
        for (int k = 0; k < x.size(); ++k) {
            x[k] = b[k];
            double diag;
            for (int s = matrix.matrix[k].j; s < matrix.matrix[k + 1].j; ++s) {
                if (matrix.matrix[s].i == k)
                    diag = matrix.matrix[s].value;
                else
                    x[k] -= x0[matrix.matrix[s].i] * matrix.matrix[s].value;
            }
            x[k] /= diag;
        }
        x0 = x;
           std::vector<T> r(matrix.matrix.size());
    for(int i = 0; i < matrix.matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * x_0[i];
        nev.push_back(sqrt(r * r));
        count++;
    }
    return std::make_pair(x0, std::make_pair(count, nev));
}

#endif