#include <stdio.h>

double f1(double x) {
    return 1 + x*x;
}
double f2(double x) {
    return x / (1 + x * x);
}
double trapezoidal_integration(double a, double b, int n, double (*func)(double)) {
    double h = (b - a) / n;
    double sum = 0.0;
    
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        if (i == 0 || i == n) {
            sum += func(x);
        } else {
            sum += 2 * func(x);
        }
    }
    
    return (h / 2) * sum;
}

int main() {
    int n = 100;

    double a = 0.0;
    double b = 1.0;
    double result = trapezoidal_integration(a, b, n, f1);
    printf("∫ (1 + x^2) dx = %.5f\n", result);

    a = 0.0;
    b = 3.0;
    result = trapezoidal_integration(a, b, n, f2);
    printf("∫ x / (1 + x^2) dx = %.5f\n", result);
    return 0;
}
