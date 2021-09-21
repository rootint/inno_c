#include <stdio.h>

int main() {
    short n;
    scanf("%hd", &n);
    int k = 0;
    for (short i = 1; i <= n; i++) {
        for (short l = 0; l < (n - i + 1) / 2; l++) {
            printf(" ");
        }
        for (short j = 1; j <= i; j++) {
            k++;
            printf("%d", k);   
        }
        printf("\n");
    }
    return 0;
}