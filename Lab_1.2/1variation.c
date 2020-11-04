#include <stdio.h>
#include <math.h>

int main () {
    int n;
    double multiply = 1, result = 0;
    printf ("Enter N: ");
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            multiply *= j + cos (j);
        }
        result += (pow (4, i) - i) / multiply;
        multiply = 1;
    }
    printf ("Result: %.7lf", result);
    return 0;
}
