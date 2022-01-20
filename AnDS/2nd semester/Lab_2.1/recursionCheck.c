#include <stdio.h>

int main() {
    int n;
    float x;
    double F, sum;
    printf("|x| < 1\nInput X:");
    scanf("%f", &x);
    if (x > 1 || x < -1) return printf("Invalid number!");

    printf("Input N:");
    scanf("%d", &n);
    if (n < 1) return printf("Invalid number!");

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            F = 1;
        } else if (i == 2) {
            F = (-1 * x) / 2;
        } else {
            F *= (-1) * x * (2 * i - 3) / (2 * i);
        }
        sum += F;
        printf("%d. F = %lf sum = %lf\n", i, F, sum);
    }
}
