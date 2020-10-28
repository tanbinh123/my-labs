#include <stdio.h>

int main () {
    float x;
    printf("Enter X: ");
    scanf("%f", &x);
    printf("X = %f\n", x);
        if (x >= -49 && x < -10 || x > 0 && x <= 10) {
            printf("Y = %f", 10 * (x * x * x) + 7 * x / 5 + 2);
        } else
        if (x > 20) {
            printf("Y = %f", - x + 9);
        } else
            printf("X does not belong to the given interval!");
    return 0;
}