#include <stdio.h>

int main () {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    printf("Sum: %d\n", x+y);
    printf("Difference: %d\n", x-y);
    printf("Multiplication: %d\n", x*y);
    if (y == 0) {
        printf("y != 0\n");
    } else {
        printf("Division: %f\n", (float) x/y);
    }
    return 0;
}