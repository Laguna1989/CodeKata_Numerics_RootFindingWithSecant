#include "secant.hpp"
#include <gtest/gtest.h>
#include <tuple>

TEST(RootfindingSecantTest, LinearFunction)
{
    auto func = [](double x) { return x; };

    double const x0 = 1.0;
    double const x1 = 2.0;

    double const xprime = secant(func, x0, x1, 0.01);
    ASSERT_DOUBLE_EQ(0.0, xprime);
}

TEST(RootfindingSecantTest, LinearFunctionWithOffset)
{
    auto const func = [](double x) { return x + 5; };

    double const x0 = 1.0;
    double const x1 = 2.0;

    double const xprime = secant(func, x0, x1, 0.01);
    ASSERT_DOUBLE_EQ(-5.0, xprime);
}

TEST(RootfindingSecantTest, PolynomSecondOrder)
{
    auto const func = [](double x) { return x * x; };

    double const x0 = 1.0;
    double const x1 = 2.0;

    double const delta = 0.00001;

    double const xprime = secant(func, x0, x1, delta);
    ASSERT_LT(abs(xprime - 0), sqrt(delta));
}

TEST(RootfindingSecantTest, PolynomSecondOrderWithOffset)
{
    auto const func = [](double x) { return x * x - 1; };

    double const x0 = 3.0;
    double const x1 = 2.0;

    double const delta = 0.00001;

    double const xprime = secant(func, x0, x1, delta);
    ASSERT_LT(abs(xprime - 1.0), delta);
}

class RootfindingSecantWithStartParamTestFixture
    : public ::testing::TestWithParam<std::tuple<double, double>> {
};

TEST_P(RootfindingSecantWithStartParamTestFixture, TrascendentFunction)
{
    auto const func = [](double x) { return cos(x) - x; };

    double const x0 = std::get<0>(GetParam());
    double const x1 = std::get<1>(GetParam());

    double const delta = 0.00001;
    double const expected_root = 0.739085;

    double const calculated_root = secant(func, x0, x1, delta);
    ASSERT_LT(abs(calculated_root - expected_root), delta);
}

INSTANTIATE_TEST_SUITE_P(RootfindingSecantWithStartParamTest,
    RootfindingSecantWithStartParamTestFixture,
    ::testing::Values(std::make_tuple(3.0, 2.0), std::make_tuple(2.0, 3.0),
        std::make_tuple(0.1, 3.0), std::make_tuple(2.5, 0.1), std::make_tuple(0.5, 0.1)));
