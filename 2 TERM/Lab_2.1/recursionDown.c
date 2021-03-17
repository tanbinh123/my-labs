#include <stdio.h>

double recursionDown(int n, int i, double x, double tempF, double sum) {
    double F = -1;
    sum += tempF;
    printf("%d. F = %lf tempF = %lf sum = %lf\n", n, F, tempF, sum);
    if (n == 1) {
        F = tempF;
    } else if (n == i) {
        tempF = (-1 * x) / 2;
        F = recursionDown(n-1, i, x, tempF, sum);
    } else {
        tempF *= (-1) * x * (2 * (2+i-n) - 3) / (2 * (2+i-n));
        F = recursionDown(n-1, i, x, tempF, sum);
    }
    printf("%d. F = %lf tempF = %lf sum = %lf\n", n, F, tempF, sum);
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
    recursionDown(n, n, x, 1, 0);
}
