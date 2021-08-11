#include "secant.hpp"
#include <gtest/gtest.h>
#include <tuple>

using namespace ::testing;

class SecantSlopeTestFixture
    : public ::testing::TestWithParam<
          std::tuple<std::function<double(double)>, double, double, double>> {
};

TEST_P(SecantSlopeTestFixture, SlopeOfLinearFunction)
{
    auto const func = std::get<0>(GetParam());
    double const x0 = std::get<1>(GetParam());
    double const x1 = std::get<2>(GetParam());

    double const expected = std::get<3>(GetParam());

    auto const d = calculate_secant_slope(func, x0, x1);

    ASSERT_DOUBLE_EQ(expected, d);
}

INSTANTIATE_TEST_SUITE_P(SecantSlopeLinearFunctionTest, SecantSlopeTestFixture,
    Values(std::make_tuple([](double x) { return x; }, 0.0, 1.0, 1.0),
        std::make_tuple([](double x) { return x; }, 1.0, 0.0, 1.0),
        std::make_tuple([](double x) { return x; }, 100.0, 0.0, 1.0),
        std::make_tuple([](double x) { return x; }, 0.001, 0.0001, 1.0)));

INSTANTIATE_TEST_SUITE_P(SecantSlopeParabolaFunctionTest, SecantSlopeTestFixture,
    Values(std::make_tuple([](double x) { return x * x; }, 0.0, 1.0, 1.0),
        std::make_tuple([](double x) { return x * x; }, 1.0, 2.0, 3.0),
        std::make_tuple([](double x) { return x * x; }, -1.0, -2.0, -3.0),
        std::make_tuple([](double x) { return x * x; }, -1.0, 1.0, 0.0)));
