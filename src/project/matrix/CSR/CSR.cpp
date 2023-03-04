#include<iostream>
#include<vector>
#include<stdlib.h>
#include<array>
#include "CSR.h"

CSR::CSR(std::vector<std::vector<double>> a) {
    matrix.resize(3);
	for(std::size_t i = 0; i < a.size(); i++) {
        for(std::size_t j = 0; j < a[0].size(); j ++) {
            if(a[i][j] != 0) {
                std::size_t N = matrix[0].size();
                matrix[0].resize(N + 1);
                matrix[1].resize(N + 1);
                matrix[2].resize(N + 1);
                matrix[0][N] = i;
                matrix[1][N] = j;
                matrix[2][N] = a[i][j];
            }
        }
    }
}

[[nodiscard]] std::vector<std::vector<double>> CSR::returnMatrix() {
	return matrix;
}