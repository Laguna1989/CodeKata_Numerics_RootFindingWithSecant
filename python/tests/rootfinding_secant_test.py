from math import sqrt, cos
import pytest

from secant import secant


def test_rootfinding_secant_linear_function():
    def f(x):
        return x

    x0 = 1.0
    x1 = 2.0

    x = secant(f, x0, x1, 0.01)
    assert x == 0.0


def test_rootfinding_secant_linear_function_with_offset():
    def f(x):
        return x + 5.0

    x0 = 1.0
    x1 = 2.0

    x = secant(f, x0, x1, 0.01)
    assert x == -5.0


def test_rootfinding_secant_qudaratic_function():
    def f(x):
        return x * x

    x0 = 1.0
    x1 = 2.0

    delta = 0.00001

    x = secant(f, x0, x1, delta)
    assert abs(x - 0) < sqrt(delta)


def test_rootfinding_secant_qudaratic_function_with_offset():
    def f(x):
        return x * x - 1.0

    x0 = 3.0
    x1 = 2.0

    delta = 0.00001

    x = secant(f, x0, x1, delta)
    assert abs(x - 1.0) < delta


@pytest.mark.parametrize("x0, x1", [(3.0, 2.0),
                                    (2.0, 3.0),
                                    (0.1, 3.0),
                                    (2.5, 0.1),
                                    (0.5, 0.1)])
def test_rootfinding_secant_transcendent_function_with_starting_points(x0, x1):
    def f(x):
        return cos(x) - x

    delta = 0.00001
    expected_root = 0.739085
    calculated_root = secant(f, x0, x1, delta)

    assert abs(expected_root - calculated_root) < delta
