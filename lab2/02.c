#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n * 2; i += 2) {
        for (int j = n - i / 2; j > 1; j--) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }   
    return 0;
}