#ifndef SLAU_SWEEPMETHOD_H
#define SLAU_SWEEPMETHOD_H

#include<iostream>
#include<vector>
#include<array>
#include "../matrix/ThreeDiag/ThreeDiag.h"

class sweepMethod {
private:
    std::vector<double> freeCoeff;
    std::vector<std::vector<double>> threeDiagMatrix;
public:
    sweepMethod(std::vector<double>a, std::vector<double> b, std::vector<double> c, std::vector<double> free);
    std::vector<double> sweep();
};
#endif