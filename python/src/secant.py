def calculate_secant_slope(f, x0, x1):
    return (f(x1) - f(x0)) / (x1 - x0)


def secant(f, x0, x1, delta):
    x = x1
    xlast = x0
    v = f(x)

    while (abs(v) > delta):
        d = calculate_secant_slope(f, x, xlast)
        xlast = x
        x = x - v / d
        v = f(x)

    return x