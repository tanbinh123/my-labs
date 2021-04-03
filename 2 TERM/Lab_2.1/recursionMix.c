#include <stdio.h>

double sum = 0;
double recursionMix(int n, int i, double x, double F) {
    printf("%d. F = %lf sum = %lf\n", n, F, sum);
    if (n == 1) {
        F = 1;
        sum = F;
    } else if (n == i) {
        F *= (-1 * x) / 2;
        sum = F + recursionMix(n-1, i, x, F);
    } else {
        F *= (-1) * x * (2 * (2+i-n) - 3) / (2 * (2+i-n));
        sum = F + recursionMix(n-1, i, x, F);
    }
    printf("%d. F = %lf sum = %lf\n", n, F, sum);
    return sum;
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
    recursionMix(n, n, x, 1);
}
