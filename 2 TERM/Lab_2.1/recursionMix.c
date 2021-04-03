#include <stdio.h>

double recursionDown(int n, int i, double x, double tempF) {
    double F = -1, sum = 0;
    printf("%d. F = %lf tempF = %lf sum = %lf\n", n, F, tempF, sum);
    if (n == 1) {
        F = 1;
        sum = 1;
    } else if (n == i) {
        tempF *= (-1 * x) / 2;
        sum = tempF + recursionDown(n-1, i, x, tempF);
    } else {
        tempF *= (-1) * x * (2 * (2+i-n) - 3) / (2 * (2+i-n));
        sum = tempF + recursionDown(n-1, i, x, tempF);
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
    recursionDown(n, n, x, 1);
}
