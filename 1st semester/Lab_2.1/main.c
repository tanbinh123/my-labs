#include <stdio.h>

int main() {
    double x = 6.5;
    double matrix[7][7] = {
            {10, 9, 8.7, 7, 6, 3, 1},
            {8, 7.2, 6.5, 5, 4, 3.1, 2},
            {9, 8, 7.9, 7.8, 5, 4, 1.4},
            {9.3, 9, 6, 4, 3.8, 3, 2},
            {10, 8.5, 7, 6.5, 6.5, 2.8, 1},
            {8.4, 8, 7, 4, 3.8, 2.6, 2},
            {9, 8.3, 6, 5, 4, 3, 1}
    };
    printf("Needed 'X' = %.1lf\n", x);
    printf("Matrix:\n");
    for (int i = 0; i < 7; i++) {
        for(int j=0; j < 7; j++) {
            printf("%.1lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for( int j = 0; j < 7; j++){
        int i = 0;
        int left = 0;
        int right = 6;
        while(left <= right) {
            i = (left + right) / 2;
            if (matrix[j][i] > x) { left = i+1; }
            else
                if (matrix[j][i] < x) { right = i-1; }
            else
                break;
        }
        if(matrix[j][i] == x) {
            printf("'X' in %d row: yes;\n", j+1);
            printf("His coordinate: (%d; %d)\n\n", j+1, i+1);
        } else {
            printf("'X' in %d row: no\n", j+1);
        }
    }
}
