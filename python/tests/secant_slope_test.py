import pytest
from secant import calculate_secant_slope


def linear_function(x):
    return x


def quadratic_function(x):
    return x * x


@pytest.mark.parametrize("f, x0, x1, expected_value", [(linear_function, 0.0, 1.0, 1.0),
                                                       (linear_function, 1.0, 0.0, 1.0),
                                                       (linear_function, 100.0, 0.0, 1.0),
                                                       (linear_function, 0.001, 0.0001, 1.0)])
def test_secant_slope_linear_function(f, x0, x1, expected_value):
    d = calculate_secant_slope(f, x0, x1)

    assert expected_value == pytest.approx(d)


@pytest.mark.parametrize("f, x0, x1, expected_value", [(quadratic_function, 0.0, 1.0, 1.0),
                                                       (quadratic_function, 1.0, 2.0, 3.0),
                                                       (quadratic_function, -1.0, -2.0, -3.0),
                                                       (quadratic_function, -1.0, 1.0, 0.0)])
def test_secant_slope_quadratic_function(f, x0, x1, expected_value):
    d = calculate_secant_slope(f, x0, x1)

    assert expected_value == pytest.approx(d)
