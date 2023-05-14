#include "../src/project/solver/SimpleIteration.h"
#include <vector>
#include <fstream>
#include "../src/project/solver/SIMCHebeshev.h"

template<typename T>
std::pair<std::vector<T>, std::pair<size_t, std::vector<double>>> Simple_iteration_method
(const std::vector<T>& x_0, const std::vector<T>& b, double tau, double accuracy, CSR<T> matrix) 
{
    std::vector<T> x = x_0;
    std::vector<T> r(matrix.size());
    for(int i = 0; i < matrix.size(); i++)
        r[i] = b[i] - matrix[i].value * x[i];
    size_t count = 0;
    std::vector<double> nev{std::sqrt(r * r)};
    while (nev[count] > accuracy) {
        std::vector<T> r(matrix.size());
    for(int i = 0; i < matrix.size(); i++)
        r[i] = b[i] - matrix[i].value * x[i];
        x = x + tau * r;
        nev.push_back(std::sqrt(r * r));
        count++;
    }
    return std::make_pair(x, std::make_pair(count, nev));
}

int main() {
    double accuracy = 1e-13;

    double eig_max = 59.82;
    double eig_min = 12.18;

    double a = 6; 
    double b = 18;
    double tau1 = 1 / eig_max;
    double tau2 = 2 / (eig_max + eig_min);
    size_t r = 3;

    size_t N = 289;
    
    std::vector<double> x_0(N);
    std::vector<double> c(N, 3);

    std::vector<std::vector<double>> vec;
    vec.resize(N);
    for (int i = 0; i < N; ++i)
        vec[i].resize(N);
    
    for (int i = 1; i < vec.size() - 1; ++i) {
        vec[i][i] = 2 * b;
        vec[i + 1][i] = a;
        vec[i][i - 1] = a;
    }

    vec[0][0] = 2 * b;
    vec[N - 1][N - 1] = 2 * b;
    
    for (int i = 0; i < vec.size() - 17; ++i) {
        vec[i][i + 17] = a;
        vec[i + 17][i] = a;
    }

    CSR<double> matrix(vec);


    auto res1 = Simple_iteration_method(x_0, c, tau1, accuracy, matrix);
    auto res2 = Simple_iteration_method(x_0, c, tau2, accuracy, matrix);
    auto res3 = SIMCHebeshev(x_0, c , r, eig_min, eig_max, accuracy, matrix);

    std::ofstream out{"result.txt"};
    out << "Simple Iteration for tau1:\n"; 
    for (int i = 0; i < res1.second.second.size(); ++i) {
        out << std::fixed << res1.second.second[i] << std::endl;    
    }
    out << "Simple Iteration for tau2:\n"; 
    for (int i = 0; i < res1.second.second.size(); ++i) {
        out << std::fixed << res2.second.second[i] << std::endl;    
    }
    out << "SIMCHebeshov:\n"; 
    for (int i = 0; i < res1.second.second.size(); ++i) {
        out << std::fixed << res3.second.second[i] << std::endl;    
    }


    return 0;


}