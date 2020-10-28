#include <stdio.h>

int main () {
    float x;
    printf("Enter X: ");
    scanf("%f", &x);
    printf("X = %f \n", x);
        if (x > 20) {
            printf("У = %f", - x + 9);
        } else
          if (x >= -49) {
            if (x < -10) {
                printf("Y = %f", 10 * (x * x * x) + 7 * x / 5 + 2);
            } else
              if (x > 0) {
                if (x <= 10) {
                    printf("Y = %f", 10 * (x * x * x) + 7 * x / 5 + 2);
                } else
                    printf("X does not belong to the given interval!");
              } else
                  printf("X does not belong to the given interval!");
          } else
              printf("X does not belong to the given interval!");
    return 0;
}
