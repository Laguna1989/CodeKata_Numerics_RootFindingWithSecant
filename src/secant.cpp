#include "secant.hpp"

double calculate_secant_slope(std::function<double(double)> f, const double x0, const double x1)
{
    return (f(x1) - f(x0)) / (x1 - x0);
}

const double secant(std::function<double(double)> f, const double x0, const double x1, double delta)
{
    double x = x1;
    double xlast = x0;
    double v = f(x);

    while (abs(v) > delta) {
        double const d = calculate_secant_slope(f, x, xlast);
        xlast = x;
        x = x - v / d;
        v = f(x);
    }
    return x;
}
