#include <gtest/gtest.h>
#include "../src/project/containers/Norm.h"
#include "../src/project/containers/vector.h"
#include "../src/project/matrix/CSR/CSR.h"
#include "../src/project/matrix/dense/dense.h"
#include "../src/project/matrix/ThreeDiag/ThreeDiag.h"
#include "../src/project/solver/DescentMethod.h"
#include "../src/project/solver/Gauss-Seilder.h"
#include "../src/project/solver/Gauss-SeilderChebesev.h"
#include "../src/project/solver/GradientMethod.h"
#include "../src/project/solver/JACOBI.h"
#include "../src/project/solver/SIMCHebeshev.h"
#include "../src/project/solver/SimpleIteration.h"
#include "../src/project/solver/SOR.h"
#include "../src/project/solver/SSOR-Chebeshev.h"
#include "../src/project/solver/sweepMethod.h"

/*
TEST(ThreeDiagonalMatrix, slae1) {
    std::vector<double> a = {-1., -1., -1.};
    std::vector<double> b = {4., 4., 4., 4.};
    std::vector<double> c = {-1., -1., -1.};
    std::vector<double> f = {12., 14., -10., -7.};

    sweepMethod A(a, b, c, f);
    auto x = A.sweep();

    ASSERT_DOUBLE_EQ(x[0], 3.);
    ASSERT_DOUBLE_EQ(x[1], 4.);
    ASSERT_DOUBLE_EQ(x[2], -3.);
    ASSERT_DOUBLE_EQ(x[2], -2.);
}
*/
/**/
TEST(JACOBI_test, csr1) {
    std::vector<std::vector<double>> a;
    a.push_back({10., -1./2.});
    a.push_back({-1./2., 10.});
    CSR<double> A_m(a);
    std::vector<double> b = {1., 3.};
    std::vector<double> x_expected = {46./399., 122./399.};
    std::vector<double> x0 = {0., 0.};

    double tolerance = 1e-10;
    auto x = Jacobi_method(x0, b, tolerance, A_m);
    for (auto i = 0; i < 2; ++i) {
        EXPECT_NEAR(x_expected[i], x.second.second[i], tolerance);
    }
}
/*
TEST(Jacobi_solver, slae1) {
    double A[2][2] = {
            {10, -1./2.},
            {-1./2., 10}
    };

    matrix<double, 2, 2> A_m{};
    for (auto i = 0; i < 2; ++i) {
        for (auto j = 0; j < 2; ++j) {
            A_m(i, j) = A[i][j];
        }
    }
    matrix<double, 2, 1> b{};
    b(0, 0) = 1.;
    b(1, 0) = 3.;

    matrix<double, 2, 1> x_expected{};
    x_expected(0, 0) = 46./399.;
    x_expected(1, 0) = 122./399.;

    matrix<double, 2, 1> x0{};
    x0(0, 0) = 0.;
    x0(1, 0) = 0.;

    double tolerance = 1e-10;
    matrix<double, 2, 1> x = jacobi_solver(A_m, b, x0, tolerance);
    for (auto i = 0; i < 2; ++i) {
        EXPECT_NEAR(x_expected(i, 0), x(i, 0), tolerance);
    }
}

TEST(Gauss_Seidel_solver, csr1) {
    csr<double> A_m(2, 2,
                    {
                            {0, 0, 10.},
                            {0, 1, -1./2.},
                            {1, 0, -1./2.},
                            {1, 1, 10.}
                    }
                    );
    std::vector<double> b = {1., 3.};
    std::vector<double> x_expected = {46./399., 122./399.};
    std::vector<double> x0 = {0., 0.};

    double tolerance = 1e-10;
    auto x = gauss_seidel_solver(A_m, b, x0, tolerance);
    for (auto i = 0; i < 2; ++i) {
        EXPECT_NEAR(x_expected[i], x[i], tolerance);
    }
}

TEST(Gauss_Seidel_solver, slae1) {
    double A[2][2] = {
            {10, -1./2.},
            {-1./2., 10}
    };

    matrix<double, 2, 2> A_m{};
    for (auto i = 0; i < 2; ++i) {
        for (auto j = 0; j < 2; ++j) {
            A_m(i, j) = A[i][j];
        }
    }
    matrix<double, 2, 1> b{};
    b(0, 0) = 1.;
    b(1, 0) = 3.;

    matrix<double, 2, 1> x_expected{};
    x_expected(0, 0) = 46./399.;
    x_expected(1, 0) = 122./399.;

    matrix<double, 2, 1> x0{};
    x0(0, 0) = 0.;
    x0(1, 0) = 0.;

    double tolerance = 1e-10;
    matrix<double, 2, 1> x = gauss_seidel_solver(A_m, b, x0, tolerance);
    for (auto i = 0; i < 2; ++i) {
        EXPECT_NEAR(x_expected(i, 0), x(i, 0), tolerance);
    }
}

TEST(Cheb_SIM, slae1) {
    std::vector<double> b = {12./35., 92./16.};
    csr<double> A(2, 2, {
            {0, 0, 2.},
            {0, 1, 1.},
            {1, 0, 1.},
            {1, 1, 3.}
    });

    std::vector<double> x0 = {10., 0.};
    std::vector<double> x_ref = {-661./700., 781./350.};
    double tolerance = 1e-10;
    std::vector<double> x = ChebyshevSIM(A, b, x0, tolerance, (std::sqrt(5.) + 5.)/2., (-std::sqrt(5.) + 5.)/2.);
    for (std::size_t i = 0; i < 2; ++i) {
        EXPECT_NEAR(x[i], x_ref[i], tolerance);
    }
}

TEST(SOR, slae1) {
    std::vector<double> b = {12./35., 92./16.};
    csr<double> A(2, 2, {
            {0, 0, 2.},
            {0, 1, 1.},
            {1, 0, 1.},
            {1, 1, 3.}
    });

    std::vector<double> x0 = {10., 0.};
    std::vector<double> x_ref = {-661./700., 781./350.};
    double tolerance = 1e-10;
    double w = 0.2;
    std::vector<double> x = SOR(A, b, x0, w, tolerance);
    for (std::size_t i = 0; i < 2; ++i) {
        EXPECT_NEAR(x[i], x_ref[i], tolerance);
    }
}

TEST(SSOR, slae1) {
    std::vector<double> b = {12./35., 92./16.};
    csr<double> A(2, 2, {
            {0, 0, 2.},
            {0, 1, 1.},
            {1, 0, 1.},
            {1, 1, 3.}
    });

    std::vector<double> x0 = {10., 0.};
    std::vector<double> x_ref = {-661./700., 781./350.};
    double tolerance = 1e-10;
    double w = 0.2;
    std::vector<double> x = SSOR(A, b, x0, w, tolerance);
    for (std::size_t i = 0; i < 2; ++i) {
        EXPECT_NEAR(x[i], x_ref[i], tolerance);
    }
}

TEST(GD, slae1) {
    std::vector<double> b = {12./35., 92./16.};
    csr<double> A(2, 2, {
            {0, 0, 2.},
            {0, 1, 1.},
            {1, 0, 1.},
            {1, 1, 3.}
    });

    std::vector<double> x0 = {10., 0.};
    std::vector<double> x_ref = {-661./700., 781./350.};
    double tolerance = 1e-10;
    std::vector<double> x = GD(A, b, x0, tolerance);
    for (std::size_t i = 0; i < 2; ++i) {
        EXPECT_NEAR(x[i], x_ref[i], tolerance);
    }
}

TEST(CG, slae1) {
    std::vector<double> b = {12./35., 92./16.};
    csr<double> A(2, 2, {
            {0, 0, 2.},
            {0, 1, 1.},
            {1, 0, 1.},
            {1, 1, 3.}
    });

    std::vector<double> x0 = {10., 0.};
    std::vector<double> x_ref = {-661./700., 781./350.};
    double tolerance = 1e-10;
    std::vector<double> x = CG(A, b, x0, tolerance);
    for (std::size_t i = 0; i < 2; ++i) {
        EXPECT_NEAR(x[i], x_ref[i], tolerance);
    }
}

TEST(HeavyBall, slae1) {
    std::vector<double> b = {12./35., 92./16.};
    csr<double> A(2, 2, {
            {0, 0, 2.},
            {0, 1, 1.},
            {1, 0, 1.},
            {1, 1, 3.}
    });

    std::vector<double> x0 = {10., 0.};
    std::vector<double> x_ref = {-661./700., 781./350.};
    double tolerance = 1e-10;
    std::vector<double> x = HeavyBall(A, b, x0, tolerance);
    for (std::size_t i = 0; i < 2; ++i) {
        EXPECT_NEAR(x[i], x_ref[i], tolerance);
    }
}*/

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}