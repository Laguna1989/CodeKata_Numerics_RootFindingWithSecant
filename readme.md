# Overview

This is a Code Kata about numerical rootfinding with the Secant method. Please check out the
other [Code Nummies](https://github.com/Laguna1989/CodeNummies_Overview).

# Theory

## Rootfinding

Rootfinding is a central problem in maths. If there is no analytic solution for an equation, e.g. `x = cos(x)`, numeric
rootfinding yields an approximated solution for the equation, by solving `0 = cos(x) - x`.

Other algorithms for rootfinding
are [Bisection](https://github.com/Laguna1989/CodeKata_Numerics_RootFindingWithBisection) and
the [Newton-Raphson method](https://github.com/Laguna1989/CodeKata_Numerics_RootFindingWithNewtonRaphson)

## The Secant Method

![ani](https://user-images.githubusercontent.com/2394228/128999088-339f6a65-aa3e-4026-bca4-59eadbf87635.gif)

We know that a function `f(x)` has a zero at `x'` close to two starting values `x0` and `x1`. The idea of the Secant
methods is to calculate the secant, which touches `f(x)` at `x0` and `x1`. When compared to Newton-Raphson, the secant
is used instead of the tangent to calculate the next iteration step.

The slope of the secant is given by

<img src="https://render.githubusercontent.com/render/math?math=d(x_0%2C%20x_1)%20%3D%20%5Cfrac%7Bf(x_1)%20-%20f(x_0)%7D%7Bx_1-x_0%7D">


This can be used in the actual calculation of the next iteration

<img src="https://render.githubusercontent.com/render/math?math=x_2%20%3D%20x_1%20-%20%5Cfrac%7Bf(x_1)%7D%7Bd(x_0%2C%20x_1)%7D">


The iteration ends, when `f(x)` is smaller than the accepted error `delta`.

### Benefits

* Faster convergence than bisection
* Minimal knowledge needed (no derivative)

### Limitations

* Needs **two** good starting points
* Slower convergence than Newton-Raphson

# Exercise

## 1. Calculation of the secant slope

First, implement the function to calculate the slope for the secant. The
function `double calculate_secant_slope(std::function<double(double)> f, const double x0, const double x1)` can be found
in the file `src/secant.cpp`. The tests in `tests/secant_slope_test.cpp` will help you with the implementation.

## Implementation of the Secant method

Now it is time to actually implement the secant method. Implement the
function `const double secant(std::function<double(double)> f, const double x0, const double x1, double delta)`
in `src/secant.cpp`. The tests in `tests/rootfinding_secant_test.cpp` will help you with the implementation.

## Things that can go wrong

Take a look at the function `f(x) = cos(x)`. What could happen, if you pick two unlucky starting points, e.g. `x0 = 0`
and `x1 = 2.1 * pi`? How could you protect the algorithm against such issues?

# References

* [Secant method on Wikipedia](https://en.wikipedia.org/wiki/Secant_method)
* [Secant method by Oscar Veliz (youtube)](https://www.youtube.com/watch?v=_MfjXOLUnyw&ab_channel=OscarVeliz)
