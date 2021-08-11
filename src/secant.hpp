#ifndef CODE_KATA_SECANT_HPP
#define CODE_KATA_SECANT_HPP

#include <functional>

double calculate_secant_slope(std::function<double(double)> f, const double x0, const double x1);

const double secant(
    std::function<double(double)> f, const double x0, const double x1, double delta);

#endif // CODE_KATA_SECANT_HPP
