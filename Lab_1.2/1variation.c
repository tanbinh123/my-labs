#include <stdio.h>
#include <math.h>

int main () {
    int n, counter = 0;
    double multiply = 1, degree = 1, result = 0;
    printf ("Enter N: ");
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            multiply *= j + cos (j);
            counter += 3;
        }
        degree *= 4;
        result += (degree - i) / multiply;
        multiply = 1;
        counter += 4;
    }
    printf ("Result: %.7lf \n", result);
    printf ("Number of operations: %d", counter);
    return 0;
}
