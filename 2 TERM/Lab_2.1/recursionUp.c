#include <stdio.h>

double sum = 0;
double recursionUp(int n, double x) {
    double F = -1;
    printf("%d. F = %lf sum= %lf\n", n, F, sum);
    if (n == 1) {
        F = 1;
        sum += F;
    } else if (n == 2) {
        F = (-1 * x) / 2;
        recursionUp(n-1, x);
        sum += F;
    } else {
        F = recursionUp(n-1, x) * (-1) * x * (2 * n - 3) / (2 * n);
        sum += F;
    }
    printf("%d. F = %lf sum = %lf\n", n, F, sum);
    return F;
}

int main() {
    int n;
    float x;
    printf("|x| < 1\nInput X:");
    scanf("%f", &x);
    if (x > 1 || x < -1) return printf("Invalid number!");

    printf("Input N:");
    scanf("%d", &n);
    if (n < 1) return printf("Invalid number!");
    recursionUp(n, x);
}
