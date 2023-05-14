#include "sweepMethod.h"

sweepMethod::sweepMethod(std::vector<double> a, std::vector<double> b, std::vector<double> c, std::vector<double> free) {
    ThreeDiagonalMatrix threeDiagonalMatrix(a, b, c);
    threeDiagMatrix = threeDiagonalMatrix.returnMatrix();
    freeCoeff = free;
}

std::vector<double> sweepMethod::sweep() {
    std::vector<double> matrix_X;
    std::vector<double> V;
    std::vector<double> U;
    int N = threeDiagMatrix.size();
    matrix_X.resize(N);
    V.resize(N);
    U.resize(N);
    
    V[0] = threeDiagMatrix[0][1] / (-threeDiagMatrix[0][0]);
    U[0] = (-freeCoeff[0]) / (-threeDiagMatrix[0][0]);
    for (int i = 1; i < N - 1; i++) {
        V[i] = threeDiagMatrix[i][i + 1] / (-threeDiagMatrix[i][i] - threeDiagMatrix[i][i - 1] * V[i - 1]);
        U[i] = (threeDiagMatrix[i][i - 1] * U[i - 1] - freeCoeff[i]) / (-threeDiagMatrix[i][i] - threeDiagMatrix[i][i - 1] * V[i - 1]);
    }
    V[N - 1] = 0;
    U[N - 1] = (threeDiagMatrix[N - 1][N - 2] * U[N - 2] - freeCoeff[N - 1]) / (-threeDiagMatrix[N - 1][N - 1] - threeDiagMatrix[N - 1][N - 2] * V[N - 2]);

    matrix_X[N - 1] = U[N - 1];
    for (int i = N - 1; i >= 0; i--)
        matrix_X[i - 1] = V[i - 1] * matrix_X[i] + U[i - 1];

    return matrix_X;
}