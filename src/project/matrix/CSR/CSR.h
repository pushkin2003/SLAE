#ifndef SLAU_CSR_H
#define SLAU_CSR_H

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<array>
#include<cmath>

template<typename T>
struct elemCSR {
	size_t i;
	size_t j;
	T value;
};

template<typename T>
class CSR {
private:
	
	int size;
public:
	CSR(std::vector<std::vector<T>> a);
	size_t returnNumb(int i, int j);
	[[nodiscard]]int sizeMatrix();
	std::vector<elemCSR<T>> matrix;
};

#endif