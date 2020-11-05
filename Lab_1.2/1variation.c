#include <stdio.h>
#include <math.h>

int main () {
    int n, counter = 0;
    double multiply = 1, result = 0;
    printf ("Enter N: ");
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            multiply *= j + cos (j);
            counter ++;
        }
        result += (pow (4, i) - i) / multiply;
        multiply = 1;
        counter ++;
    }
    printf ("Result: %.7lf \n", result);
    printf ("Number of operations: %d", counter);
    return 0;
}
