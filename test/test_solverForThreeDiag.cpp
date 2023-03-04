#include "gtest/gtest.h"
#include "../src/project/matrix/ThreeDiag.h"
#include "../src/project/solver/sweepMethod.h"

TEST(threediagonalmatrix, matrix_passed) {
    std::vector<double> a{1, 2, 3};
    std::vector<double> b{1, 2, 3, 4};
    std::vector<double> c{1, 2, 3};
    std::vector<double> free{1, 2, 3, 4};
    std::vector<double> solve{1, 2, 3, 4};
    sweepMethod sweep(a, b, c, free);
    
    std::vector<double> res = sweep.sweep();
    ASSERT_EQ(res, solve);
}