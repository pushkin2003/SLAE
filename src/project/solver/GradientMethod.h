#ifndef GradientMethod
#define GradientMethod
#include <fstream>
#include "../matrix/CSR/CSR.h"

template<typename T>
std::pair<std::vector<T>, std::pair<size_t, std::vector<double>>> CG_method
(const std::vector<T>& x_0, const std::vector<T>& b, double accuracy, CSR<T> matrix) 
 {

    std::ofstream out;
    out.open("../../../test/result.txt");

    std::vector<T> x = x_0;
    std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        r[i] = -b[i] + matrix.matrix[i].value * x[i];
    std::vector<T> d = r;
    double beta;
    double alpha;
    std::vector<T> Ad(x_0.size());
    size_t count = 0;
    std::vector<double> nev{std::sqrt(r * r)};
    while (nev[count] > accuracy) {
        for (int i = 0; i < x_0.size(); ++i) {
            if (!isZero(r)) {
                std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        Ad[i] = matrix.matrix[i].value * d[i];
            alpha = r * r / (d * Ad);
            x = x - alpha * d;
            out << d[0] << " " << d[x_0.size() - 1] << std::endl;
            beta = 1 / (r * r);
            r = r - alpha * Ad;
            beta *= (r * r);
            d = r + beta * d;
            nev.push_back(sqrt(r * r));
            count++;
        }
        else
            return std::make_pair(x, std::make_pair(count, nev));
        }
    }
    return std::make_pair(x, std::make_pair(count, nev));
}

#endif