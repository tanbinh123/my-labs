#include <stdio.h>
#include <math.h>

int main () {
    int n, counter = 0;
    double multiply = 1, result = 0;
    printf ("Enter N: ");
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
            multiply *= i + cos (i);
            result += (pow (4, i) - i) / multiply;
            counter ++;
        }
    printf ("Result: %.7lf\n", result);
    printf ("Number of operations: %d", counter);
    return 0;
}
