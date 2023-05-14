#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ranges>
#include<array>
#include<cmath>
#include "dense.h"

dense::dense(std::vector<std::vector<double>> a) {
   matrix.resize((a.size( )));  
    for(size_t i = 0; i < a.size(); i++)
        matrix[i].resize(a[0].size());

	for(size_t i = 0; i < a.size(); i++)
        for(size_t j = 0; j < a[0].size(); j++)
            matrix[i][j] = a[i][j];
}

[[nodiscard]]std::vector<double> dense::multi(std::vector<double> vec) {
    std::vector<double> res;
    res.resize(matrix.size());
    for(std::size_t i = 0; i < matrix.size(); i++) {
        res[i] = 0;
        for(std::size_t j = 0; j < vec.size(); j++) {
            res[i] += matrix[i][j] * vec[j];
        }
    }
    return res;
}

std::size_t multipSc(std::vector<double> a, std::vector<double> b) {
    std::size_t res = 0;
    for(std::size_t i = 0; i < a.size(); i++)
        res += a[i] * b[i];
    return res;
}

std::vector<double> multipNumb(double b, std::vector<double> a) {
    for(std::size_t i = 0; i < a.size(); i++) 
        a[i] *= b;
    return a;
}

std::vector<double> addV(std::vector<double> a, std::vector<double> b) {
    std::vector<double> res(a.size());
    for(std::size_t i = 0; i < res.size(); i++)
        res[i] = a[i] + b[i];
    return res;
}

std::vector<double> delV(std::vector<double> a, std::vector<double> b) {
    std::vector<double> res(a.size());
    for(std::size_t i = 0; i < res.size(); i++)
        res[i] = a[i] - b[i];
    return res;
}

std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> dense::DrHouse() {

    std::vector<std::vector<double>> R = matrix;
    
    std::size_t dimension = R.size();
    
    std::vector<double> x(dimension);
    for (std::size_t i = 0; i < dimension; ++i)
        x[i] = R[i][0];
    
    std::vector<double> base(dimension);
    base[0] = 1;
    
    std::vector<double> n(dimension);
    if (x[0] > 0)
        n = addV(x, multipNumb(sqrt(multipSc(x, x)), base));
    else
        n = delV(x, multipNumb(sqrt(multipSc(x, x)), base));
    
    std::vector<std::vector<double>> Q;
    Q.resize(n.size());
    for(std::size_t i = 0; i < n.size(); i++)
        Q[i].resize(n.size());

    std::vector<double> e_0(n.size());
    for (std::size_t j = 0; j < n.size(); ++j) {
        std::fill(e_0.begin(), e_0.end(), 0);
        e_0[j] = 1;
        e_0 = delV(e_0, multipNumb(2.0 * (n[j] / multipSc(n, n)), n));
        for (std::size_t i = 0; i < n.size(); ++i)
            Q[i * n.size() + j][0] = e_0[i];
    }
    
    R[0][0] -= 2 * n[0] * multipSc(x, n) / multipSc(n, n);
    for (std::size_t i = 1; i < R.size(); ++i)
        R[i][0] = 0;
    
    for (std::size_t j = 1; j < R[0].size(); ++j) {
        std::vector<double> x1(dimension);
        for (std::size_t i = 0; i < x1.size(); ++i)
            x1[i] = R[i][j];
        for (std::size_t i = 0; i < dimension; ++i)
            R[i][j] -= 2 * n[i] * multipSc(x1, n) / multipSc(n, n);
    }
    
    std::size_t amount;
    if(R.size() == R[0].size()) 
        amount = R[0].size() - 1;
    else
        amount = R[0].size();

    for (std::size_t k = 1; k < amount; ++k) {
        
        dimension--;
        x.resize(dimension);
        n.resize(dimension);
        base.resize(dimension);
        
        for (std::size_t i = 0; i < dimension; ++i)
            x[i] = R[i + k][k];
        if (x[0] > 0)
            n = addV(x, multipNumb(sqrt(multipSc(x, x)), base));
        else
            n = delV(x, multipNumb(sqrt(multipSc(x, x)), base));
        
        R[k][k] -= 2 * n[0] * multipSc(x, n) / multipSc(n, n);
        for (std::size_t i = k + 1; i < R.size(); ++i)
            R[i][k] = 0;
        // Changing other columns after column number k
        for (std::size_t j = k + 1; j < R[0].size(); ++j) {
            for (std::size_t i = 0; i < dimension; ++i)
                x[i] = R[k + i][j];
            for (std::size_t i = 0; i < dimension; ++i)
                R[k + i][j] -= 2 * n[i] * multipSc(x, n) / multipSc(n, n);
        }
        // Step k, finding Q_k
        for (std::size_t i = 0; i < Q.size(); ++i) {
            for (std::size_t j = 0; j < dimension; ++j)
                x[j] = Q[i][j + k];
            for (std::size_t j = 0; j < dimension; ++j)
                Q[i][j + k] -= 2 * n[j] * multipSc(x, n) / multipSc(n, n);
        }
    }
    return std::make_pair(Q, R);
}

[[nodiscard]]std::vector<std::vector<double>> dense::returnMatrix() {
	return matrix;
}