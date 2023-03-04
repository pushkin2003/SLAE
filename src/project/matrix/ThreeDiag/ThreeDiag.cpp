#include<iostream>
#include<vector>
#include<stdlib.h>
#include<array>
#include "ThreeDiag.h"

ThreeDiagonalMatrix::ThreeDiagonalMatrix(std::vector<double> a, std::vector<double> b, std::vector<double> c) {
	int N = b.size();
	matrix.resize(N);
	for(int i = 0; i < N; i++)
		matrix[i].resize(N);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			matrix[i][j] = 0.0;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) {
			if(i == j)
				matrix[i][j] = b[i];
			if(i == j + 1)
				matrix[i][j] = a[j];
			if(j == i + 1)
				matrix[i][j] = c[j];
		}
}

std::vector<std::vector<double>> ThreeDiagonalMatrix::returnMatrix() {
	return matrix;
}