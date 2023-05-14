#ifndef GAUSS_SEILDER
#define GAUSS_SEILDER

#include "../matrix/CSR/CSR.h"

template<typename T>
std::pair<std::vector<T>, std::pair<size_t, std::vector<double>>> Gauss_Seidel_method
(const std::vector<T>& x_0, const std::vector<T>& b, double accuracy, const CSR<T>& matrix)
{

    std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * x_0[i];
        
    size_t count = 0;
    std::vector<double> nev {sqrt(r * r)};
    while (nev[count] > accuracy) {
        for (int k = 0; k < x_0.size(); ++k) {
            x_0[k] = b[k];
            double diag;
            for (int s = matrix.matrix[k].j; s < matrix.matrix[k + 2].j; ++s) {
                if (matrix.matrix[s].i == k)
                    diag = matrix.matrix[s].value;
                else
                    x_0[k] -= x_0[matrix.matrix[s].i] * matrix.matrix[s].value;
            }
            x_0[k] /= diag;
        }
        std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * x_0[i];
        nev.push_back(sqrt(r * r));
        count++;
    }
    return std::make_pair(x_0, std::make_pair(count, nev));
}

#endif