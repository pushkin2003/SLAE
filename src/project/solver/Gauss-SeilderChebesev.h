#ifndef GAUSS_SEILDERChevesev
#define GAUSS_SEILDERChevesev

#include "../matrix/CSR/CSR.h"

template<typename T>
std::vector<T> Sym_GS_make_iteration(const std::vector<T>& x_0, const std::vector<T>& b, CSR<T> matrix)  {
    std::vector<T> x = x_0;
    for (int k = 0; k < x.size(); ++k) {
        x[k] = b[k];
        double diag;
        for (int s = matrix.matrix[k].j; s < matrix.matrix[k + 1].j; ++s) {
            if (matrix.matrix[s].i == k)
                diag = matrix.matrix[s].value;
            else
                x[k] -= x[matrix.matrix[s].i] * matrix.matrix[s].value;
        }
        x[k] /= diag;
    }
    for (int k = x.size() - 1; k >= 0; --k) {
        x[k] = b[k];
        double diag;
        for (int s = matrix.matrix[k].j; s < matrix.matrix[k + 1].j; ++s) {
            if (matrix.matrix[s].i == k)
                diag = matrix.matrix[s].value;
            else
                x[k] -= x[matrix.matrix[s].i] * matrix.matrix[s].value;
        }
        x[k] /= diag;
    }
    return x;
}
    
template<typename T>
std::pair<std::vector<T>, std::pair<size_t, std::vector<double>>> Symmetrical_GS_method
(const std::vector<T>& x_0, const std::vector<T>& b, double rho, double accuracy, CSR<T> matrix)
{
    std::vector<T> y_0 = x_0;
    std::vector<T> y_1 = Sym_GS_make_iteration(y_0, b, matrix);
    double mu_0 = 1;
    double mu_1 = 1 / rho;
    std::vector<T> temp = Sym_GS_make_iteration(y_1, b, matrix);
    std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * y_1[i];
    std::vector<double> nev {sqrt(r * r)};
    size_t count = 0;
    while (nev[count] > accuracy) {
        y_0 = -mu_0 * y_0 + 2 * mu_1 / rho * temp;
        mu_0 = 2 / rho * mu_1 - mu_0;
        y_0 /= mu_0;
        temp = Sym_GS_make_iteration(y_0, b);
        y_1.swap(y_0);
        std::swap(mu_0, mu_1);
        std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * x_0[i];
        nev.push_back(sqrt(r * r));
        count++;
    }
    return std::make_pair(y_1, std::make_pair(count, nev));
}

#endif