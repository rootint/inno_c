#include <stdio.h>

void swap (int *a, int *b) {
    // printf("swap1: %p %p\n", a, b);
    // printf("swap1: %d %d\n\n", *a, *b);
    int c;
    c = *a;
    *a = *b;
    *b = c;
    // printf("swap2: %p %p\n", a, b);
    // printf("swap2: %d %d\n\n", *a, *b);
}

int main () {
    int a, b;
    scanf("%d%d", &a, &b);
    // printf("before_swap: %p %p\n\n", &a, &b);
    swap(&a, &b);
    // printf("after_swap: %p %p\n", &a, &b);
    printf("after_swap: %d %d\n\n", a, b);
    return 0;
}