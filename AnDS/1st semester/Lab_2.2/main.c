#include <stdio.h>

int main() {
    int i, j;
    double matrix[7][7] = {
   //     Variation:
            {2, 5, 3, 7, 1, 4, 6},
   //         {1, 2, 3, 4, 5, 6, 7},
   //         {7, 6, 5, 4, 3, 2, 1},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0}
    };

    printf("Before sort:\n");
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            printf("%.0lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (i = 0; i <= 6; i += 2) {
        int row = 0, T = matrix[row][i];
        j = 0;

        while (matrix[row][j] < T) { j += 2; }

        for (int k = i - 2; k >= j; k -= 2) {
            matrix[row][k+2] = matrix[row][k];
        }
        matrix[row][j] = T;
    }

    printf("After sort:\n");
    for (i = 0; i < 7; i++) {
        for (j=0; j < 7; j++) {
            printf("%.0lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
