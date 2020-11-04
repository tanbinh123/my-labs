#include <stdio.h>
#include <math.h>

int main () {
    int n;
    double multiply = 1, result = 0;
    printf ("Enter N: ");
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
            multiply *= i + cos (i);
            result += (pow (4, i) - i) / multiply;
        }
    printf ("Result: %.7lf", result);
    return 0;
}
