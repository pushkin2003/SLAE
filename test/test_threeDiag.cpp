#include "gtest/gtest.h"
#include "../src/projetc/matrix/ThreeDiag.h"

TEST(THREEDIAGONAL, CSR_CAST) {
    std::vector<double> a{1, 2, 3};
    std::vector<double> b{1, 2, 3, 4};
    std::vector<double> c{1, 2, 3};
    ThreeDiagonalMatrix matrix(a, b, c);

    std::vector<std::vector<double>> solve{{1, 1, 0, 0},
                                           {1, 2, 2, 0},
                                           {0, 2, 3, 3},
                                           {0, 0, 3, 4}};
    std::vector<std::vector<double>> res = matrix.returnMatrix();
    ASSERT_EQ(res, solve);
}